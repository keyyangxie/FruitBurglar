/* Project:		GSMPre
   File Name:	GameStateManager.c
   Author:		刘芳
   Date:		2015-9-15
   Purpose:		GSM  */

#include "GameStateManager.h"
#include "GameStateList.h"
#include "System.h"
#include "Level1.h"
#include "Level2.h"

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

// GSM初始化
void GSM_Initialize(int level)
{
	Current = Previous = Next = level;

	fprintf(fp,"GSM:Initialize\n");
}

// GSM更新
void GSM_Update(int level)
{
	// Function Pointer Point to functions
	switch(level)
	{
		case GS_L1:
			{
				pLoad = Load1;
				pIni = Ini1;
				pUpdate = Update1;
				pDraw = Draw1;
				pFree = Free1;
				pUnload = Unload1;
				break;
			}
			case GS_L2:
			{
				pLoad = Load2;
				pIni = Ini2;
				pUpdate = Update2;
				pDraw = Draw2;
				pFree = Free2;
				pUnload = Unload2;
				break;
			}
	}

	fprintf(fp,"GSM:Update\n");
}

//------------------------------------------------------------------------------
// Private Functions:
//------------------------------------------------------------------------------

