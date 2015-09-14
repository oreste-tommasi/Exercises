#include "pch.h"
#include "User.h"
#include "Kernel.h"

PFBeginPaint BeginPaint = nullptr;
PFEndPaint EndPaint = nullptr;
PFGetDC GetDC = nullptr;

FuncTable userFuncTable[] = 
{
	{(void**)&BeginPaint, "BeginPaint"}, 
	{(void**)&EndPaint, "EndPaint"}, 
	{(void**)&GetDC, "GetDC"}
};

BOOL userLoadLibrary(char* library)
{
	BOOL returnValue = TRUE;
	HMODULE hUser = nullptr;

	if (!KernelLoaded)
	{
		returnValue = kernelLoadLirary();
	}

	if (TRUE == returnValue)
	{
		if (nullptr == (hUser = LoadLibraryA(library)))
		{
			returnValue = false;
		}
		else
		{
			int funcStructSize = sizeof(FuncTable);
			int funcTableSize = sizeof(userFuncTable);
			int funcCount = funcTableSize / funcStructSize;
			returnValue = kernelSetFuncs(hUser, userFuncTable, funcCount);
		}
	}

	return returnValue;
}