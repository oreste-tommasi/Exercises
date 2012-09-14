// TestMinidump.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "windows.h"

#include <dbghelp.h>
#include <shellapi.h>
#include <shlobj.h>

typedef	CHAR		_WCHAR;

int GenerateDump( _WCHAR* szAppName, _WCHAR* szVersion, EXCEPTION_POINTERS* pExceptionPointers, _WCHAR* outFileDir )
{	
	BOOL bMiniDumpSuccessful;
	_WCHAR szPath[MAX_PATH]; 
	_WCHAR szFileName[MAX_PATH]; 
	//_WCHAR* szAppName = L"AppName";
	//_WCHAR* szVersion = L"v1.0";
	DWORD dwBufferSize = MAX_PATH;
	HANDLE hDumpFile;
	SYSTEMTIME stLocalTime;
	MINIDUMP_EXCEPTION_INFORMATION ExpParam;

	GetLocalTime( &stLocalTime );

	sprintf_s( szPath, MAX_PATH, "d:\\Temp\\" );  //   GetTempPath( dwBufferSize, szPath );

	sprintf_s( szFileName, MAX_PATH, "%s%s", szPath, szAppName );
	//    StringCchPrintf( szFileName, MAX_PATH, L"%s%s", szPath, szAppName );
	CreateDirectory( szFileName, NULL );

	if( outFileDir )
	 strcpy_s( outFileDir, MAX_PATH, szFileName );

	sprintf_s( szFileName, MAX_PATH, "%s%s\\%s-%04d%02d%02d-%02d%02d%02d-%ld-%ld.dmp", 
				szPath, szAppName, szVersion, 
				stLocalTime.wYear, stLocalTime.wMonth, stLocalTime.wDay, 
				stLocalTime.wHour, stLocalTime.wMinute, stLocalTime.wSecond, 
				GetCurrentProcessId(), GetCurrentThreadId());
	//StringCchPrintf( szFileName, MAX_PATH, L"%s%s\\%s-%04d%02d%02d-%02d%02d%02d-%ld-%ld.dmp", 
	//           szPath, szAppName, szVersion, 
	//           stLocalTime.wYear, stLocalTime.wMonth, stLocalTime.wDay, 
	//           stLocalTime.wHour, stLocalTime.wMinute, stLocalTime.wSecond, 
	//           GetCurrentProcessId(), GetCurrentThreadId());
	hDumpFile = CreateFile(szFileName, GENERIC_READ|GENERIC_WRITE, 
				 FILE_SHARE_WRITE|FILE_SHARE_READ, 0, CREATE_ALWAYS, 0, 0);

	ExpParam.ThreadId = GetCurrentThreadId();
	ExpParam.ExceptionPointers = pExceptionPointers;
	ExpParam.ClientPointers = TRUE;

	bMiniDumpSuccessful = MiniDumpWriteDump(GetCurrentProcess(), GetCurrentProcessId(), 
					  hDumpFile, MiniDumpWithDataSegs, &ExpParam, NULL, NULL);

	return EXCEPTION_EXECUTE_HANDLER;
}

int crash2()
{
	return crash2();
}

int crash1()
{
	int*	p = 0;
	int	a = *p;
	return a;
}	


int _tmain(int argc, _TCHAR* argv[])
{
	char		appName[256]="TestMiniDump", appVers[64]="1.0";
	char		fileDir[MAX_PATH]="";

	_try
	{
		crash1();
	}
	__except( GenerateDump( appName, appVers, GetExceptionInformation(), fileDir ) )
	{
/*
		::MessageBox( GetMainHwnd(), "The application has been terminated because of an error.\r\n"
											  "A dump of the current application stack has been created in the folder which is going to be shown.", 
						 "Error Report", MB_OK | MB_ICONWARNING );
*/
		//ShellExecute(NULL, "open", fileDir, NULL, NULL, SW_SHOWDEFAULT);

		ExitProcess(1);
		return -1;
	}


	system("pause");
	return 0;
}

