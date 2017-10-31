// duiresbuilder.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdlib.h>
#include <Windows.h>
#include <ShellAPI.h>

//使用7z打包资源文件
//参数1 uires所在路径
//参数2 目标zip文件目录
int _tmain(int argc, _TCHAR* argv[])
{
	for (size_t i = 0; i < argc; i++)
	{
		wprintf(L"%s\n", argv[i]);
	}

	if (argc < 3)
	{
		printf("参数太少\n");
		return 0;
	}

	TCHAR szPath[260] ;
	TCHAR szDst[260] ;
	TCHAR szExePath[260] ;
	TCHAR szCmdLine[1024];
	_tcscpy(szPath,argv[1]);
	_tcscpy(szDst,szPath);
	_tcscat(szDst,_T("\\duires.zip"));
	_tcscat(szPath,_T("\\uires\\*"));
	_tcscpy(szExePath,argv[0]);
	*_tcsrchr(szExePath,'\\') = '\0';
	_tcscat(szExePath,_T("\\DuilibResBuilder\\7z.exe"));
	swprintf(szCmdLine,_T("%s a -tzip \"%s\" \"%s\""), szExePath,szDst,szPath);
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	memset(&si, 0, sizeof(STARTUPINFO));
	si.wShowWindow = SW_HIDE;
	memset(&pi, 0, sizeof(PROCESS_INFORMATION));
	si.cb = sizeof(STARTUPINFO);
	CreateProcess(NULL, szCmdLine, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi);
	WaitForSingleObject(pi.hProcess,5*60*1000);
	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);
	wprintf(L"%s\n",szCmdLine);
	return 0;
}

