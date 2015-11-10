/* Project:		GSMPre
   File Name:	Level1.c
   Author:		刘芳
   Date:		2015-9-15
   Purpose:		关卡1  */

#include <stdio.h>
#include "GameStateList.h"
#include "System.h"
#include "Level1.h"

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
static int Level1_Counter;     // 控制关卡1运行次数

//------------------------------------------------------------------------------
// Private Function Declarations:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Public Functions:
//------------------------------------------------------------------------------

void Load1(void)
{
	FILE *fpLevCounter;

	// Append "Level1:Load" into Output.txt
	fprintf(fp, "Level1:Load\n");

	// Open file Level1_Counter.txt
	if ((fpLevCounter = fopen("Level1_Counter.txt","r")) == NULL)
	{
		printf("The file Level1_Counter is NULL. \n");
		return;
	}

	// Read
	fscanf(fpLevCounter,"%d",&Level1_Counter);

	fclose(fpLevCounter);
}

void Ini1(void)
{
	// Append "Level1:Initialize" into Output.txt
	fprintf(fp, "Level1:Initialize\n");
}

void Update1(void)
{
	// Append Level1:Update into Output.txt
	fprintf(fp, "Level1:Update\n");

	Level1_Counter -= 1;

	if (Level1_Counter == 0)
		Next = GS_L2;
}

void Draw1(void)
{
	// Append "Level1:Draw" into Output.txt
	fprintf(fp, "Level1:Draw\n");
}

void Free1(void)
{
	// Append "Level1:Free" into Output.txt
	fprintf(fp, "Level1:Free\n");
}

void Unload1(void)
{
	// Append "Level1:Unload" into Output.txt
	fprintf(fp, "Level1:Unload\n");
}

//------------------------------------------------------------------------------
// Private Functions:
//------------------------------------------------------------------------------
