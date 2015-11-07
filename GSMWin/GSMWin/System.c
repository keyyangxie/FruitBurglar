/* Project:		GSMWin
   File Name:	System.c
   Author:		����
   Date:		
   Purpose:		ϵͳ������ */

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
// ϵͳ��ʼ��
int System_Initialize(HINSTANCE hInstance, int nCmdShow)
{
	// ׼��Output.txt
	if ((fp = fopen("Output.txt","w")) == NULL)
	{
		printf("Cannot find file Output.txt\n");
		return -1;
	}

	// Alphaϵͳ��ʼ��
	sysInitInfo.mAppInstance		= hInstance;	// WinMain�ĵ�1������
	sysInitInfo.mShow				= nCmdShow;		// WinMain�ĵ�4������
	sysInitInfo.mWinWidth			= 800; 
	sysInitInfo.mWinHeight			= 600;
	sysInitInfo.mCreateConsole		= 1;			// �Ƿ���Ҫ�򿪿���̨
	sysInitInfo.mCreateWindow		= 1;			// �Ƿ���Ҫ��������
	sysInitInfo.mWindowHandle		= NULL;			// ��Alphaȱʡ����
	sysInitInfo.mMaxFrameRate		= 60;			// ����֡�ʣ����ʹ��Alpha��֡�ʿ��ƹ��ܵĻ���
	sysInitInfo.mpWinCallBack		= Input_Handle;			// ָ�����ڹ��̺���
	sysInitInfo.mClassStyle			= CS_HREDRAW | CS_VREDRAW;		// �����ඨ����ػ淽ʽ									
	sysInitInfo.mWindowStyle		= WS_OVERLAPPEDWINDOW;			// ���ڷ��ȡֵ��WS_POPUP | WS_VISIBLE | WS_SYSMENU | WS_CLIPCHILDREN | WS_CLIPSIBLINGS;

	if(0 == AESysInit (&sysInitInfo))
		return -1;
	AESysReset();

	// ǩ��
	fprintf(fp,"System:Initialize\n");
	return 0;
}

// ϵͳ�˳�
void System_Exit(void)
{
	// Alphaϵͳ�˳�
	AESysExit();

	// ǩ�� �� Close Output.txt
	fprintf(fp,"System:Exit\n");
	fclose(fp);
}

//------------------------------------------------------------------------------
// Private Functions:
//------------------------------------------------------------------------------





