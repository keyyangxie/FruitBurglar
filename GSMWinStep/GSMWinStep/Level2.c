/* Project:		GSMWinStep
File Name:	Level2.c
Author(former):		����
Author KY
Date:
Purpose:		�ؿ�2  */

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
static float obj2X, obj2Y;		// ����2��λ��
static AEGfxVertexList*	pMesh2;	// ����2������(mesh)ģ��
static AEGfxTexture *pTex1;		// ����2������

//------------------------------------------------------------------------------
// Private Function Declarations:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Public Functions:
//------------------------------------------------------------------------------

void Load2(void)
{
	// ��������2
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

	// ��������
	pTex1 = AEGfxTextureLoad("PlanetTexture.png");

	// ǩ��
	fprintf(fp, "Level2:Load\n");
}

void Ini2(void)
{
	// Ϊ��ʼ��������׼��
	AEGfxSetBackgroundColor(0.0f, 0.0f, 0.0f);
	AEGfxSetBlendMode(AE_GFX_BM_BLEND);

	// ǩ��
	fprintf(fp, "Level2:Initialize\n");
}

void Update2(void)
{
	// ǩ��
	//fprintf(fp, "Level2:Update\n");
	// ״̬�л�
	if (KeyPressed[KeyR])
		Next = GS_Restart;
	if (KeyPressed[KeyESC])
		Next = GS_Quit;
	if (KeyPressed[Key1])
		Next = GS_L1;

	// ��������
	Input_Initialize();

	// ǩ��
	fprintf(fp, "Level2:Update\n");
}

void Draw2(void)
{
	// Drawing object 2
	// Set position for object 2
	AEGfxSetRenderMode(AE_GFX_RM_TEXTURE);   // �����������û���ģʽΪ����
	AEGfxSetPosition(0.0f, 0.0f);
	// Set texture for object 2
	AEGfxTextureSet(pTex1, 0.0f, 0.0f); // ����1������ƫ����(x,y)
	AEGfxSetTransparency(1.0f);
	AEGfxSetBlendColor(0.0f, 0.0f, 0.0, 0.0f);
	// Drawing the mesh (list of triangles)
	AEGfxMeshDraw(pMesh2, AE_GFX_MDM_TRIANGLES);

	// ǩ��
	fprintf(fp, "Level2:Draw\n");
}

void Free2(void)
{
	// ǩ��
	fprintf(fp, "Level2:Free\n");
}

void Unload2(void)
{
	// ж�ض�����Դ	
	AEGfxMeshFree(pMesh2);
	AEGfxTextureUnload(pTex1);

	// ǩ��
	fprintf(fp, "Level2:Unload\n");
}

//------------------------------------------------------------------------------
// Private Functions:
//------------------------------------------------------------------------------

