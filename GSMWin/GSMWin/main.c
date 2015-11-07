/*  Project:	GSMWin
    File:		main.c
	Author:		刘芳
	Date:		
	Purpose:	在练习1的基础上，实现基于Windows应用的游戏状态管理器
				该游戏状态管理器负责管理一个包含两个关卡的游戏
				关卡一：不再有控制关卡一运行次数的计数器
				        在关卡一有一个三角形对象
						用户可以通过上下左右箭头键控制它的移动
						同时，系统还可处理下列状态转换命令：
						R键：Restart；ESC：退出系统；2：切换到关卡2
				关卡二：不再有控制关卡二运行次数的计数器和lives
				        在关卡二有一个地球
						同关卡一一样，系统可处理下列状态转换命令：
						R键：Restart；ESC：退出系统；1：切换到关卡1
				同练习一，流程中的每一个处理需要输出标签到output.txt
*/

#include "System.h"
#include <Windows.h>
#include "GameStateList.h"
#include "GameStateManager.h"
#include "Input.h"
#include "AEEngine.h"

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

//------------------------------------------------------------------------------
// Private Function Declarations:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Public Functions:
//------------------------------------------------------------------------------
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// System Initialize
	System_Initialize(hInstance, nCmdShow);

	// GSM Initialize
	GSM_Initialize(GS_L1);

	// Game Flow
	while(Current != GS_Quit)
	{
		if(Current == GS_Restart)
		{
			Current = Previous;
			Next = Previous;
		}
		else
		{
			// GSM Update
			GSM_Update(Current);
			pLoad();
		}

		pIni();

		// Game Loop
		while(Current == Next)
		{
			AESysFrameStart();		// 帧开始：封装了PeekMessage
			// 回调函数 Input_Handle();
			pUpdate();
			pDraw();
			AESysFrameEnd();		// 帧结束
		}

		pFree();

		if(Next != GS_Restart)
			pUnload();

		Previous = Current;
		Current = Next;
	}

	// System Exit
	System_Exit();

	return 0;
}
//------------------------------------------------------------------------------
// Private Functions:
//------------------------------------------------------------------------------
