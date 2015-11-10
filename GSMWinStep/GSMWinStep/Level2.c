/* Project:		GSMWinStep
File Name:	Level2.c
Author(former):		刘芳
Author KY
Date:
Purpose:		关卡2  */

#include "Level2.h"
#include "GameStateList.h"
#include "System.h"
#include <stdio.h>
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
static float obj2X, obj2Y;		// 对象2的位置
static AEGfxVertexList*	pMesh2;	// 对象2的网格(mesh)模型
static AEGfxTexture *pTex1;		// 对象2的纹理

//------------------------------------------------------------------------------
// Private Function Declarations:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Public Functions:
//------------------------------------------------------------------------------

void Load2(void)
{
	// 创建对象2
	AEGfxMeshStart();
	AEGfxTriAdd(
		-30.0f, -30.0f, 0x00FF00FF, 0.0f, 1.0f,
		30.0f, -30.0f, 0x00FFFF00, 1.0f, 1.0f,
		-30.0f, 30.0f, 0x00F00FFF, 0.0f, 0.0f);
	AEGfxTriAdd(
		30.0f, -30.0f, 0x00FFFFFF, 1.0f, 1.0f,
		30.0f, 30.0f, 0x00FFFFFF, 1.0f, 0.0f,
		-30.0f, 30.0f, 0x00FFFFFF, 0.0f, 0.0f);
	pMesh2 = AEGfxMeshEnd();
	AE_ASSERT_MESG(pMesh2, "Failed to create mesh 2!!");

	// 载入纹理
	pTex1 = AEGfxTextureLoad("PlanetTexture.png");

	// 签到
	fprintf(fp, "Level2:Load\n");
}

void Ini2(void)
{
	// 为开始画对象做准备
	AEGfxSetBackgroundColor(0.0f, 0.0f, 0.0f);
	AEGfxSetBlendMode(AE_GFX_BM_BLEND);

	// 签到
	fprintf(fp, "Level2:Initialize\n");
}

void Update2(void)
{
	// 签到
	//fprintf(fp, "Level2:Update\n");
	// 状态切换
	if (KeyPressed[KeyR])
		Next = GS_Restart;
	if (KeyPressed[KeyESC])
		Next = GS_Quit;
	if (KeyPressed[Key1])
		Next = GS_L1;

	// 输入重置
	Input_Initialize();

	// 签到
	fprintf(fp, "Level2:Update\n");
}

void Draw2(void)
{
	// Drawing object 2
	// Set position for object 2
	AEGfxSetRenderMode(AE_GFX_RM_TEXTURE);   // 必须最先设置绘制模式为纹理
	AEGfxSetPosition(0.0f, 0.0f);
	// Set texture for object 2
	AEGfxTextureSet(pTex1, 0.0f, 0.0f); // 参数1：纹理，偏移量(x,y)
	AEGfxSetTransparency(1.0f);
	AEGfxSetBlendColor(0.0f, 0.0f, 0.0, 0.0f);
	// Drawing the mesh (list of triangles)
	AEGfxMeshDraw(pMesh2, AE_GFX_MDM_TRIANGLES);

	// 签到
	fprintf(fp, "Level2:Draw\n");
}

void Free2(void)
{
	// 签到
	fprintf(fp, "Level2:Free\n");
}

void Unload2(void)
{
	// 卸载对象资源	
	AEGfxMeshFree(pMesh2);
	AEGfxTextureUnload(pTex1);

	// 签到
	fprintf(fp, "Level2:Unload\n");
}

//------------------------------------------------------------------------------
// Private Functions:
//------------------------------------------------------------------------------

