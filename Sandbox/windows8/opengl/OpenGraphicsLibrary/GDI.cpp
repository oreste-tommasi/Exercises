#include "pch.h"
#include "Kernel.h"
#include "GDI.h"

PFBitBlt BitBlt = nullptr;
PFCreateCompatibleBitmap CreateCompatibleBitmap = nullptr;
PFCreateCompatibleDC CreateCompatibleDC = nullptr;
PFCreateDIBSection CreateDIBSection = nullptr;
PFGdiFlush GdiFlush = nullptr;
PFSelectObject SelectObject = nullptr;
extern PFChoosePixelFormat ChoosePixelFormat = nullptr;
extern PFSetPixelFormat SetPixelFormat = nullptr;
extern PFSwapBuffers SwapBuffers = nullptr;

FuncTable gdiFuncTable[] = 
{
	{(void**)&BitBlt, "BitBlt"}, 
	{(void**)&CreateCompatibleBitmap, "CreateCompatibleBitmap"}, 
	{(void**)&CreateCompatibleDC, "CreateCompatibleDC"}, 
	{(void**)&CreateDIBSection, "CreateDIBSection"}, 
	{(void**)&GdiFlush, "GdiFlush"}, 
	{(void**)&SelectObject, "SelectObject"},
	{(void**)&ChoosePixelFormat, "ChoosePixelFormat"},
	{(void**)&SetPixelFormat, "SetPixelFormat"},
	{(void**)&SwapBuffers, "SwapBuffers"}
};

BOOL gdiLoadLibrary(char* library)
{
	BOOL returnValue = TRUE;
	HMODULE hGdi = nullptr;

	if (!KernelLoaded)
	{
		returnValue = kernelLoadLirary();
	}

	if (TRUE == returnValue)
	{
		if (nullptr == (hGdi = LoadLibraryA(library)))
		{
			returnValue = false;
		}
		else
		{
			int funcStructSize = sizeof(FuncTable);
			int funcTableSize = sizeof(gdiFuncTable);
			int funcCount = funcTableSize / funcStructSize;
			returnValue = kernelSetFuncs(hGdi, gdiFuncTable, funcCount);
		}
	}

	return returnValue;
}

HWND GetHWND(CoreWindow^ window)
{
	HRESULT hr = S_OK;
	HWND hWnd = nullptr;
	struct __declspec(uuid("45D64A29-A63E-4CB6-B498-5781D298CB4F")) __declspec(novtable)
	ICoreWindowInterop : IUnknown
	{
		virtual HRESULT __stdcall get_WindowHandle(HWND * hwnd) = 0;
		virtual HRESULT __stdcall put_MessageHandled(unsigned char) = 0;
	};
	Microsoft::WRL::ComPtr<ICoreWindowInterop> interop;
	
	if (S_OK != (hr = reinterpret_cast<IUnknown *>(window)->QueryInterface(interop.GetAddressOf())))
	{
		hWnd = nullptr;
	}
	else if (S_OK != (hr = interop->get_WindowHandle(&hWnd)))
	{
		hWnd = nullptr;
	}

	return hWnd;
}