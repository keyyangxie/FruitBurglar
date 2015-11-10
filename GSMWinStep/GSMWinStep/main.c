/* Project:		GSMWinStep
File Name:	main.c
Author(former):		Áõ·¼
Author KY
Date:		...
Purpose:		...
*/

#include <Windows.h>
#include "System.h"
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
	AESysFrameStart();
	//Input_Handle();  »Øµ÷º¯Êý
	pUpdate();
	pDraw();
	AESysFrameEnd();
	}

	pFree();

	if(Next != GS_Restart)
	pUnload();

	Previous = Current;
	Current = Next;
	}

	// System Exit
	system("pause");
	System_Exit();

	return 0;
}
