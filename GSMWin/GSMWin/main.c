/*  Project:	GSMWin
    File:		main.c
	Author:		����
	Date:		
	Purpose:	����ϰ1�Ļ����ϣ�ʵ�ֻ���WindowsӦ�õ���Ϸ״̬������
				����Ϸ״̬�������������һ�����������ؿ�����Ϸ
				�ؿ�һ�������п��ƹؿ�һ���д����ļ�����
				        �ڹؿ�һ��һ�������ζ���
						�û�����ͨ���������Ҽ�ͷ�����������ƶ�
						ͬʱ��ϵͳ���ɴ�������״̬ת�����
						R����Restart��ESC���˳�ϵͳ��2���л����ؿ�2
				�ؿ����������п��ƹؿ������д����ļ�������lives
				        �ڹؿ�����һ������
						ͬ�ؿ�һһ����ϵͳ�ɴ�������״̬ת�����
						R����Restart��ESC���˳�ϵͳ��1���л����ؿ�1
				ͬ��ϰһ�������е�ÿһ��������Ҫ�����ǩ��output.txt
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
			AESysFrameStart();		// ֡��ʼ����װ��PeekMessage
			// �ص����� Input_Handle();
			pUpdate();
			pDraw();
			AESysFrameEnd();		// ֡����
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
