// stdafx.h : ��׼ϵͳ�����ļ��İ����ļ���
// ���Ǿ���ʹ�õ��������ĵ�
// �ض�����Ŀ�İ����ļ�
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             //  �� Windows ͷ�ļ����ų�����ʹ�õ���Ϣ
// Windows ͷ�ļ�:
#include <windows.h>
#include <objbase.h>
#include <zmouse.h>

#include "..\DuiLib\UIlib.h"
using namespace DuiLib;

#ifdef _DEBUG
#       pragma comment(lib, "..\\Bin\\DuiLib_d.lib")
#else
#       pragma comment(lib, "..\\Bin\\DuiLib.lib")
#endif