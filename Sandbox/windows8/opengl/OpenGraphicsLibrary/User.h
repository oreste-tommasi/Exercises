#pragma once

#include <wrl/client.h>

typedef struct _PAINTSTRUCT
{
  HDC  hdc;
  BOOL fErase;
  RECT rcPaint;
  BOOL fRestore;
  BOOL fIncUpdate;
  BYTE rgbReserved[32];
} PAINTSTRUCT;

typedef HDC (WINAPI *PFBeginPaint)(HWND hwnd, PAINTSTRUCT *lpPaint);
typedef BOOL (WINAPI *PFEndPaint)(HWND hWnd, const PAINTSTRUCT *lpPaint);

typedef HDC (WINAPI *PFGetDC)(HWND hWnd);

extern PFBeginPaint BeginPaint;
extern PFEndPaint EndPaint;
extern PFGetDC GetDC;

BOOL userLoadLibrary(char* library);