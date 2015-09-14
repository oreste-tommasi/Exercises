#pragma once

#include <wrl/client.h>
#include <agile.h>

using namespace Windows::UI::Core;


typedef BOOL (WINAPI *PFBitBlt)(HDC hdcDest, int nXDest, int nYDest, int nWidth, int nHeight, HDC hdcSrc, int nXSrc, int nYSrc, DWORD dwRop);
typedef HBITMAP (WINAPI *PFCreateCompatibleBitmap)(HDC hdc, int nWidth, int nHeight);
typedef HDC (WINAPI *PFCreateCompatibleDC)(HDC hdc);
typedef HBITMAP (WINAPI *PFCreateDIBSection)(HDC hdc, const BITMAPINFO *pbmi, UINT iUsage, VOID **ppvBits, HANDLE hSection, DWORD dwOffset);
typedef BOOL (WINAPI *PFGdiFlush)(void);
typedef HGDIOBJ (WINAPI *PFSelectObject)(HDC hdc, HGDIOBJ hgdiobj);
typedef int (WINAPI *PFChoosePixelFormat)(HDC hdc, PIXELFORMATDESCRIPTOR *ppfd);
typedef BOOL (WINAPI *PFSetPixelFormat)(HDC hdc, int format, PIXELFORMATDESCRIPTOR *ppfd);
typedef BOOL (WINAPI *PFSwapBuffers)(HDC hDC);

extern PFBitBlt BitBlt;
extern PFCreateCompatibleBitmap CreateCompatibleBitmap;
extern PFCreateCompatibleDC CreateCompatibleDC;
extern PFCreateDIBSection CreateDIBSection;
extern PFGdiFlush GdiFlush;
extern PFSelectObject SelectObject;
extern PFChoosePixelFormat ChoosePixelFormat;
extern PFSetPixelFormat SetPixelFormat;
extern PFSwapBuffers SwapBuffers;

BOOL gdiLoadLibrary(char* library);
HWND GetHWND(CoreWindow^ window);
