/* Project:		GSMWin
   File Name:	System.c
   Author:		刘芳
   Date:		
   Purpose:		系统管理器 */

#include "System.h"
#include "AEEngine.h"
#include "Input.h"

#pragma comment (lib, "Alpha_Engine.lib")

//------------------------------------------------------------------------------
// Private Consts:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Private Structures:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Public Variables:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Private Variables:
//------------------------------------------------------------------------------
AESysInitInfo sysInitInfo;
//------------------------------------------------------------------------------
// Private Function Declarations:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Public Functions:
//------------------------------------------------------------------------------
// 系统初始化
int System_Initialize(HINSTANCE hInstance, int nCmdShow)
{
	// 准备Output.txt
	if ((fp = fopen("Output.txt","w")) == NULL)
	{
		printf("Cannot find file Output.txt\n");
		return -1;
	}

	// Alpha系统初始化
	sysInitInfo.mAppInstance		= hInstance;	// WinMain的第1个参数
	sysInitInfo.mShow				= nCmdShow;		// WinMain的第4个参数
	sysInitInfo.mWinWidth			= 800; 
	sysInitInfo.mWinHeight			= 600;
	sysInitInfo.mCreateConsole		= 1;			// 是否需要打开控制台
	sysInitInfo.mCreateWindow		= 1;			// 是否需要创建窗口
	sysInitInfo.mWindowHandle		= NULL;			// 让Alpha缺省处理
	sysInitInfo.mMaxFrameRate		= 60;			// 设置帧率（如果使用Alpha的帧率控制功能的话）
	sysInitInfo.mpWinCallBack		= Input_Handle;			// 指定窗口过程函数
	sysInitInfo.mClassStyle			= CS_HREDRAW | CS_VREDRAW;		// 窗口类定义的重绘方式									
	sysInitInfo.mWindowStyle		= WS_OVERLAPPEDWINDOW;			// 窗口风格，取值：WS_POPUP | WS_VISIBLE | WS_SYSMENU | WS_CLIPCHILDREN | WS_CLIPSIBLINGS;

	if(0 == AESysInit (&sysInitInfo))
		return -1;
	AESysReset();

	// 签到
	fprintf(fp,"System:Initialize\n");
	return 0;
}

// 系统退出
void System_Exit(void)
{
	// Alpha系统退出
	AESysExit();

	// 签到 并 Close Output.txt
	fprintf(fp,"System:Exit\n");
	fclose(fp);
}

//------------------------------------------------------------------------------
// Private Functions:
//------------------------------------------------------------------------------





