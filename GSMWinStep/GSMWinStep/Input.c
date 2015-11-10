/* Project:		GSMWinStep
File Name:	Input.c
Author(former):		刘芳
Author KY
Date:		2015-9-15
Purpose:		输入模块  */

#include "System.h"

//新加全局变量
enum{
	KeyR,
	KeyESC,
	Key1,
	Key2,
	KeyUp,
	KeyDown,
	KeyLeft,
	KeyRight,
	KeyNUM    // 总放在最后一个
};
boolean KeyPressed[KeyNUM];

//新增函数
void Input_Initialize()
{
	int i;
	for (i = 0; i<KeyNUM; i++)
	{
		KeyPressed[i] = FALSE;
	}
}

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
LRESULT CALLBACK Input_Handle(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	HDC dc;           // 设备
	PAINTSTRUCT ps;   // 重绘结构

	// 签到
	//fprintf(fp,"Input:Handle\n");

	switch (msg)
	{
		//  窗口创建
	case WM_CREATE:
		break;

	case WM_LBUTTONDOWN:
		//GS_Running = 0;
		break;

	case WM_MOUSEMOVE:
		break;

		// 重绘
	case WM_PAINT:
		dc = BeginPaint(hWnd, &ps);
		EndPaint(hWnd, &ps);
		break;

		// 窗口关闭
	//case WM_DESTROY:
	//	break;
	case WM_DESTROY:
		KeyPressed[KeyESC] = TRUE;
		fprintf(fp, "Input:Forcing Shut Down\n");
		break;

	//case WM_KEYDOWN:
		//if(wParam == VK_ESCAPE)
		//GS_Running = 0;
	case WM_KEYDOWN:
		if (wParam == VK_ESCAPE)
		{
			KeyPressed[KeyESC] = TRUE;
			fprintf(fp, "Input:ESC\n");
		}
		if (wParam == 'R')
		{
			KeyPressed[KeyR] = TRUE;
			fprintf(fp, "Input:R\n");
		}
		if (wParam == '1')
		{
			KeyPressed[Key1] = TRUE;
			fprintf(fp, "Input:1\n");
		}
		if (wParam == '2')
		{
			KeyPressed[Key2] = TRUE;
			fprintf(fp, "Input:2\n");
		}
		if (wParam == VK_UP)
			KeyPressed[KeyUp] = TRUE;
		if (wParam == VK_DOWN)
			KeyPressed[KeyDown] = TRUE;
		if (wParam == VK_LEFT)
			KeyPressed[KeyLeft] = TRUE;
		if (wParam == VK_RIGHT)
			KeyPressed[KeyRight] = TRUE;
		break;

		// 窗口发生移动
	case WM_MOVE:
		break;

		// 调用默认窗口过程
	default:
		return DefWindowProc(hWnd, msg, wParam, lParam);
	}

	return 0;
}

//------------------------------------------------------------------------------
// Private Functions:
//------------------------------------------------------------------------------

