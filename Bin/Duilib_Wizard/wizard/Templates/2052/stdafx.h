// stdafx.h : ��׼ϵͳ�����ļ��İ����ļ���
// ���Ǿ���ʹ�õ��������ĵ�
// �ض�����Ŀ�İ����ļ�
//

#pragma once

#define WIN32_LEAN_AND_MEAN             //  �� Windows ͷ�ļ����ų�����ʹ�õ���Ϣ
// Windows ͷ�ļ�:
#include <windows.h>

#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <CommDlg.h>
#include <Shellapi.h>


#include "resource.h"


#include "UIlib.h"
using namespace DuiLib;
#ifdef _DEBUG
#pragma comment(lib,"duilib_d.lib")
#else
#pragma comment(lib,"duilib.lib")
#endif

