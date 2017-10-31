// Duilib_Wizard.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <atlstr.h>

using namespace std;
struct VSENVCFG
{
	CString strName;
	CString strVsDir;
	CString strDataTarget;
	CString strEntrySrc;
	CString strEntryTarget;
	CString strScriptSrc;
};
VSENVCFG* g_config[20] = {NULL};
//����Ŀ¼
CString m_strWizardDir;
CString m_strDuiPath;//

CString GetVSDir(LPCTSTR pszEnvName)
{
	CString strRet;
	strRet.GetEnvironmentVariable(pszEnvName);
	if(!strRet.IsEmpty()) strRet=strRet.Left(strRet.GetLength()-14);//14=length("Common7\Tools\")
	return strRet;
}

void ListVS()
{
	TCHAR szDir[MAX_PATH];
	GetModuleFileName(NULL,szDir,MAX_PATH);
	*_tcsrchr(szDir,'\\') = '\0';
	m_strWizardDir=szDir;
	m_strWizardDir.Append(_T("\\Duilib_Wizard"));

	CString szVsList = m_strWizardDir + _T("\\vslist.ini");
	int i=0;
	for(;;)
	{
		CString entry;
		entry.Format(_T("vs_%d"),++i);
		TCHAR szBuf[1000];
		if(0==GetPrivateProfileString(entry,_T("name"),NULL,szBuf,1000,szVsList))
			break;

		VSENVCFG *pEnvCfg=new VSENVCFG;
		pEnvCfg->strName=szBuf;
		GetPrivateProfileString(entry,_T("envname"),NULL,szBuf,1000,szVsList);
		pEnvCfg->strVsDir=GetVSDir(szBuf);
		if(pEnvCfg->strVsDir.IsEmpty())
		{
			delete pEnvCfg;
			continue;
		}
		GetPrivateProfileString(entry,_T("entryfilesrc"),NULL,szBuf,1000,szVsList);
		pEnvCfg->strEntrySrc=szBuf;
		GetPrivateProfileString(entry,_T("entryfiletarget"),NULL,szBuf,1000,szVsList);
		pEnvCfg->strEntryTarget=szBuf;
		GetPrivateProfileString(entry,_T("wizarddatatarget"),NULL,szBuf,1000,szVsList);
		pEnvCfg->strDataTarget=szBuf;

		GetPrivateProfileString(entry,_T("scriptsrc"),NULL,szBuf,1000,szVsList);
		pEnvCfg->strScriptSrc=szBuf;

		g_config[i] = pEnvCfg;
		cout<<"["<<i<<"]"<<pEnvCfg->strName<<endl;
	}

	TCHAR szPath[MAX_PATH];
	if(GetEnvironmentVariable(_T("DUIPATH"),szPath,MAX_PATH))
	{
		m_strDuiPath = szPath;
		cout<<"Duilib·����"<<szPath<<endl;
	}else
	{
		GetCurrentDirectory(MAX_PATH,szPath);
		TCHAR *pUp=_tcsrchr(szPath,_T('\\'));
		if(pUp)
		{
			_tcscpy(pUp,_T("\\DUILIB"));
			if(GetFileAttributes(szPath)!=INVALID_FILE_ATTRIBUTES)
			{
				*pUp=0;
				m_strDuiPath = szPath;
				cout<<"Duilib·����"<<szPath<<endl;
			}
		}
	}
}

LRESULT OnInstall()
{
	SetCurrentDirectory(m_strWizardDir);

	if(GetFileAttributes(_T("Wizard"))==INVALID_FILE_ATTRIBUTES)
	{
		cout<<_T("��ǰĿ¼��û���ҵ�Duilib��������")<<endl;
		return 0;
	}
	CString strDuiSrc = m_strDuiPath+_T("\\Duilib");
	if(GetFileAttributes(strDuiSrc)==INVALID_FILE_ATTRIBUTES)
	{
		cout<<_T("��ǰĿ¼��û���ҵ�Duilib��Դ����")<<endl;
		return 0;
	}
	//���û�������
	CRegKey reg;
	if(ERROR_SUCCESS==reg.Open(HKEY_LOCAL_MACHINE,_T("System\\CurrentControlSet\\Control\\Session Manager\\Environment"),KEY_SET_VALUE|KEY_QUERY_VALUE))
	{
		reg.SetStringValue(_T("DUIPATH"),m_strDuiPath);
		reg.Close();
		DWORD_PTR msgResult=0;
		//�㲥���������޸���Ϣ
		SendMessageTimeout(HWND_BROADCAST, WM_SETTINGCHANGE, 0,LPARAM(_T("Environment")), SMTO_ABORTIFHUNG, 5000, &msgResult);
	}else
	{
		cout<<_T("��ӻ�������ʧ��")<<endl;
		return 0;
	}

	//׼�������ļ�
	TCHAR szFrom[1024]={0};
	TCHAR szTo[1024]={0};
	SHFILEOPSTRUCT shfo;
	shfo.pFrom=szFrom;
	shfo.pTo=szTo;

	cout<<"������Ű�װ��Ӧ����"<<endl;
	int index = getch()-'0';
	if (index <0||index>20)
	{
		cout<<"�����±���Ч"<<endl;
		return -1;
	}
	VSENVCFG *pCfg=g_config[index];
	if(pCfg == NULL) 
	{
		cout<<"Ŀ�껷��δ��װ"<<endl;
		return -1;
	}
	cout<<"���ڰ�װ"<<pCfg->strName<<"��Ӧ��"<<endl;
	//�����������
	BOOL bOK = TRUE;
	if(bOK)
	{
		shfo.wFunc=FO_COPY;
		shfo.fFlags=FOF_NOCONFIRMMKDIR|FOF_NOCONFIRMATION;
		memset(szFrom,0,sizeof(szFrom));
		memset(szTo,0,sizeof(szTo));
		_tcscpy(szFrom,_T("entry\\*.*"));
		_tcscpy(szTo,pCfg->strVsDir);
		_tcscat(szTo,pCfg->strDataTarget);
		bOK = 0==SHFileOperation(&shfo);
	}
	//��дDuiWizard.vsz
	if(bOK)
	{
		_tcscpy(szFrom,pCfg->strEntrySrc);
		_tcscat(szFrom,_T("\\DuiWizard.vsz"));
		_tcscpy(szTo,pCfg->strVsDir);
		_tcscat(szTo,pCfg->strEntryTarget);
		_tcscat(szTo,_T("\\DuiWizard.vsz"));

		CopyFile(szFrom,szTo,FALSE);

		FILE *f=_tfopen(szTo,_T("r"));
		if(f)
		{
			char szBuf[4096];
			int nReaded=fread(szBuf,1,4096,f);
			szBuf[nReaded]=0;
			fclose(f);

			f=_tfopen(szTo,_T("w"));
			if(f)
			{//���ԭ����������д��������
				CStringA str=szBuf;
				str.Replace("%DUIPATH%",m_strDuiPath);
				fwrite((LPCSTR)str,1,str.GetLength(),f);
				fclose(f);
			}
		}
	}

	CString strMsg;
	strMsg.Format(_T("Ϊ%s��װDUILIB��:%s"),pCfg->strName,bOK?_T("�ɹ�"):_T("ʧ��"));
	cout<<strMsg<<endl;
	return 0;
}
int _tmain(int argc, _TCHAR* argv[])
{
	cout << "���������װDuilib Visual Studio ��" << endl;
	cout << "��ʼǰ�ֶ���DUIPATH��ӵ���������" << endl;
	getch();
	ListVS();
	OnInstall();
	cout<<"����������˳�"<<endl;
	getch();
	return 0;
}

