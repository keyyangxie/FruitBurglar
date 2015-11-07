/* Project:		GSMWin
   File Name:	Level1.c
   Author:		����
   Date:		
   Purpose:		�ؿ�1  */

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
static float obj1X, obj1Y;		// ����1��λ��
static AEGfxVertexList*	pMesh1;	// ����1������(mesh)ģ��

//------------------------------------------------------------------------------
// Private Function Declarations:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Public Functions:
//------------------------------------------------------------------------------

void Load1(void)
{
	// ���������ζ���
	AEGfxMeshStart();
	AEGfxTriAdd(
		-25.5f, -25.5f, 0xFFFF0000, 0.0f, 0.0f, 
		25.5f,  0.0f, 0x00FF0000, 0.0f, 0.0f,
		-25.5f,  25.5f, 0xFFFFFF00, 0.0f, 0.0f);
	// ��������pMesh1
	pMesh1 = AEGfxMeshEnd();
	AE_ASSERT_MESG(pMesh1, "Failed to create mesh 1!!");

	// ǩ��
	fprintf(fp, "Level1:Load\n");
}

void Ini1(void)
{
	// Ϊ��ʼ��������׼��
	AEGfxSetBackgroundColor(0.0f, 0.0f, 0.0f);
	AEGfxSetBlendMode(AE_GFX_BM_BLEND);

	// ����λ�ó�ʼ��
	obj1X = 0.0f;
	obj1Y = 0.0f;

	// ǩ��
	fprintf(fp, "Level1:Initialize\n");
}

void Update1(void)
{
	// ״̬�л�
	if(KeyPressed[KeyR])
		Next = GS_Restart;
	if(KeyPressed[KeyESC])
		Next = GS_Quit;
	if(KeyPressed[Key2])
		Next = GS_L2;

	// �����ƶ�
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

	// ��������
	Input_Initialize();

	// ǩ��
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

	// ǩ��
	fprintf(fp, "Level1:Draw\n");
}

void Free1(void)
{
	// ǩ��
	fprintf(fp, "Level1:Free\n");
}

void Unload1(void)
{
	// ж�ض�����Դ
	AEGfxMeshFree(pMesh1);

	// ǩ��
	fprintf(fp, "Level1:Unload\n");
}

//------------------------------------------------------------------------------
// Private Functions:
//------------------------------------------------------------------------------
