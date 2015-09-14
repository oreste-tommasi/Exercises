#include "pch.h"
#include "Kernel.h"

#include <stdio.h>

BOOL KernelLoaded = FALSE;
extern FPLoadLibraryA LoadLibraryA = nullptr;
extern FPGetProcAddressA GetProcAddressA = nullptr;
char errorMessage[1024] = {0};

char* getAddress(void)
{
	char *Addr=(char*)GetTickCount64;
	Addr=(char*)((~0xFFF)&(DWORD_PTR)Addr);
	while(Addr)
	{
		__try 
		{
			if(Addr[0]=='M' && Addr[1]=='Z') break;
		} __except(EXCEPTION_EXECUTE_HANDLER)
		{
		}
		Addr-=0x1000;
	}
	if(Addr==0) return nullptr;
	return Addr;
}

PIMAGE_NT_HEADERS WINAPI ImageNtHeader(PVOID Base)
{
	return (PIMAGE_NT_HEADERS)
		((LPBYTE) Base + ((PIMAGE_DOS_HEADER) Base)->e_lfanew);
}

PIMAGE_SECTION_HEADER WINAPI RtlImageRvaToSection( const IMAGE_NT_HEADERS *nt, HMODULE module, DWORD_PTR rva )
{
    int i;
    const IMAGE_SECTION_HEADER *sec;

    sec = (const IMAGE_SECTION_HEADER*)((const char*)&nt->OptionalHeader + nt->FileHeader.SizeOfOptionalHeader);

    for (i = 0; i < nt->FileHeader.NumberOfSections; i++, sec++)
    {
        if ((sec->VirtualAddress <= rva) && (sec->VirtualAddress + sec->SizeOfRawData > rva))
            return (PIMAGE_SECTION_HEADER)sec;
    }
    return NULL;
}

PVOID WINAPI RtlImageRvaToVa( const IMAGE_NT_HEADERS *nt, HMODULE module, DWORD_PTR rva, IMAGE_SECTION_HEADER **section )
{
    IMAGE_SECTION_HEADER *sec;

    if (section && *section)  
    {
        sec = *section;
        if ((sec->VirtualAddress <= rva) && (sec->VirtualAddress + sec->SizeOfRawData > rva))
            goto found;
    }

    if (!(sec = RtlImageRvaToSection( nt, module, rva ))) return NULL;

 found:
    if (section) *section = sec;
    return (char *)module + sec->PointerToRawData + (rva - sec->VirtualAddress);
}

PVOID WINAPI ImageDirectoryEntryToDataEx( PVOID base, BOOLEAN image, USHORT dir, PULONG size, PIMAGE_SECTION_HEADER *section )
{
    const IMAGE_NT_HEADERS *nt;
    DWORD_PTR addr;

    *size = 0;
    if (section) *section = NULL;

    if (!(nt = ImageNtHeader( base ))) return NULL;
    if (dir >= nt->OptionalHeader.NumberOfRvaAndSizes) return NULL;
    if (!(addr = nt->OptionalHeader.DataDirectory[dir].VirtualAddress)) return NULL;

    *size = nt->OptionalHeader.DataDirectory[dir].Size;
    if (image || addr < nt->OptionalHeader.SizeOfHeaders) return (char *)base + addr;

    return RtlImageRvaToVa( nt, (HMODULE)base, addr, section );
}

void *PeGetProcAddressA(void *Base, LPCSTR Name)
{
	DWORD Tmp;

	IMAGE_NT_HEADERS *NT=ImageNtHeader(Base);
	IMAGE_EXPORT_DIRECTORY *Exp=(IMAGE_EXPORT_DIRECTORY*)ImageDirectoryEntryToDataEx(Base,TRUE,IMAGE_DIRECTORY_ENTRY_EXPORT,&Tmp,0);
	if(Exp==0 || Exp->NumberOfFunctions==0)
	{
		SetLastError(ERROR_NOT_FOUND);
		return 0;
	}

	DWORD *Names=(DWORD*)(Exp->AddressOfNames+(DWORD_PTR)Base);
	WORD *Ordinals=(WORD*)(Exp->AddressOfNameOrdinals+(DWORD_PTR)Base);
	DWORD *Functions=(DWORD*)(Exp->AddressOfFunctions+(DWORD_PTR)Base);

	FARPROC Ret=0;

	if((DWORD_PTR)Name<65536)
	{
		if((DWORD_PTR)Name-Exp->Base<Exp->NumberOfFunctions)
			Ret=(FARPROC)(Functions[(DWORD_PTR)Name-Exp->Base]+(DWORD_PTR)Base);
	} 
	else
	{
		for(DWORD i=0; i<Exp->NumberOfNames && Ret==0; i++)
		{
			char *Func=(char*)(Names[i]+(DWORD_PTR)Base);
			if(Func && strcmp(Func,Name)==0)
				Ret=(FARPROC)(Functions[Ordinals[i]]+(DWORD_PTR)Base);
		}
	}

	if(Ret)
	{
		DWORD ExpStart=NT->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT].VirtualAddress+(DWORD)Base;
		DWORD ExpSize=NT->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT].Size;
		if((DWORD)Ret>=ExpStart && (DWORD)Ret<=ExpStart+ExpSize)
		{
			return 0;
		}
		return Ret;
	}

	return 0;	
}

BOOL kernelLoadLirary()
{
	BOOL returnValue = TRUE;

	if (!KernelLoaded)
	{
		char* addr = nullptr;

		if (nullptr == (addr = getAddress()))
		{
			returnValue = FALSE;
		}
		else if (nullptr == (LoadLibraryA = (FPLoadLibraryA)PeGetProcAddressA(addr,"LoadLibraryA")))
		{
			returnValue = FALSE;
		}
		else if (nullptr == (GetProcAddressA = (FPGetProcAddressA)PeGetProcAddressA(addr,"GetProcAddress")))
		{
			returnValue = FALSE;
		}
		else
		{
			KernelLoaded = TRUE;
		}
	}

	return returnValue;
}

BOOL setFunc(HMODULE module, void **func, char *funcName)
{
	BOOL returnValue = TRUE;

	if (nullptr == (*func = GetProcAddressA(module, funcName)))
	{
		sprintf_s(errorMessage, 1024, "Could not load function %s", funcName);
		returnValue = FALSE;
	}

	return returnValue;
}

BOOL kernelSetFuncs (HMODULE module, FuncTable *funcTable, int funcCount)
{
	int returnValue = TRUE;
	int funcIndex = 0;

	do
	{
		returnValue = setFunc(module, funcTable[funcIndex].func, (char*)funcTable[funcIndex].name);
		funcIndex++;
	} 
	while ( (funcIndex < funcCount) && (TRUE == returnValue) );


	return returnValue;
}