/* Project:		GSMWin
   File Name:	Level1.c
   Author:		刘芳
   Date:		
   Purpose:		关卡1  */

#include <stdio.h>
#include "GameStateList.h"
#include "System.h"
#include "Level1.h"
#include "AEEngine.h"
#include "Input.h"

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
static float obj1X, obj1Y;		// 对象1的位置
static AEGfxVertexList*	pMesh1;	// 对象1的网格(mesh)模型

//------------------------------------------------------------------------------
// Private Function Declarations:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Public Functions:
//------------------------------------------------------------------------------

void Load1(void)
{
	// 创建三角形对象
	AEGfxMeshStart();
	AEGfxTriAdd(
		-25.5f, -25.5f, 0xFFFF0000, 0.0f, 0.0f, 
		25.5f,  0.0f, 0x00FF0000, 0.0f, 0.0f,
		-25.5f,  25.5f, 0xFFFFFF00, 0.0f, 0.0f);
	// 创建对象pMesh1
	pMesh1 = AEGfxMeshEnd();
	AE_ASSERT_MESG(pMesh1, "Failed to create mesh 1!!");

	// 签到
	fprintf(fp, "Level1:Load\n");
}

void Ini1(void)
{
	// 为开始画对象做准备
	AEGfxSetBackgroundColor(0.0f, 0.0f, 0.0f);
	AEGfxSetBlendMode(AE_GFX_BM_BLEND);

	// 对象位置初始化
	obj1X = 0.0f;
	obj1Y = 0.0f;

	// 签到
	fprintf(fp, "Level1:Initialize\n");
}

void Update1(void)
{
	// 状态切换
	if(KeyPressed[KeyR])
		Next = GS_Restart;
	if(KeyPressed[KeyESC])
		Next = GS_Quit;
	if(KeyPressed[Key2])
		Next = GS_L2;

	// 对象移动
	if(KeyPressed[KeyUp])
		obj1Y += 0.5f;
	else
	if(KeyPressed[KeyDown])
		obj1Y -= 0.5f;
	if(KeyPressed[KeyLeft])
		obj1X -= 0.5f;
	else
	if(KeyPressed[KeyRight])
		obj1X += 0.5f;

	// 输入重置
	Input_Initialize();

	// 签到
	fprintf(fp, "Level1:Update\n");
}

void Draw1(void)
{
	// Drawing object 1
	AEGfxSetRenderMode(AE_GFX_RM_COLOR);
	// Set position for object 1
	AEGfxSetPosition(obj1X, obj1Y);
	// No texture for object 1
	AEGfxTextureSet(NULL, 0, 0);
	// Drawing the mesh (list of triangles)
	AEGfxSetTransparency(1);
	AEGfxSetBlendColor(0.0f, 0.0f, 0.0, 0.0f);
	AEGfxMeshDraw(pMesh1, AE_GFX_MDM_TRIANGLES);

	// 签到
	fprintf(fp, "Level1:Draw\n");
}

void Free1(void)
{
	// 签到
	fprintf(fp, "Level1:Free\n");
}

void Unload1(void)
{
	// 卸载对象资源
	AEGfxMeshFree(pMesh1);

	// 签到
	fprintf(fp, "Level1:Unload\n");
}

//------------------------------------------------------------------------------
// Private Functions:
//------------------------------------------------------------------------------
