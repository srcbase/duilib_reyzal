// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
//

#pragma once

#define WIN32_LEAN_AND_MEAN             //  从 Windows 头文件中排除极少使用的信息
// Windows 头文件:
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

