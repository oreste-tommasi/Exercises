#pragma once

#include <wrl/client.h>

typedef struct _FuncTable
{
	void **func;
	char name[50];
} FuncTable;

typedef HMODULE (WINAPI *FPLoadLibraryA)(char *);
typedef FARPROC (WINAPI *FPGetProcAddressA)(HMODULE H, char *);

extern BOOL KernelLoaded;
extern FPLoadLibraryA LoadLibraryA;
extern FPGetProcAddressA GetProcAddressA;

BOOL kernelLoadLirary();
BOOL kernelSetFuncs (HMODULE module, FuncTable *funcTable, int funcCount);