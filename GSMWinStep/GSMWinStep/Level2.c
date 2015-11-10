/* Project:		GSMPre
   File Name:	Level2.c
   Author:		刘芳
   Date:		2015-9-15
   Purpose:		关卡2  */

#include "Level2.h"
#include "GameStateList.h"
#include "System.h"
#include <stdio.h>

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
static int Level2_Counter;		// 控制关卡2的运行次数
static int Level2_Lives;		// 关卡2的玩家lives个数

//------------------------------------------------------------------------------
// Private Function Declarations:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Public Functions:
//------------------------------------------------------------------------------

void Load2(void)
{
	FILE *fpLevLives;

	// Append "Level2:Load" into Output.txt
	fprintf(fp, "Level2:Load\n");

	// Open file Level2_Lives.txt
	if ((fpLevLives = fopen("Level2_Lives.txt","r")) == NULL)
	{
		printf("The file Level2_Lives.txt is NULL. \n");
		return;
	}

	// Read
    fscanf(fpLevLives,"%d",&Level2_Lives);

	fclose(fpLevLives);
}

void Ini2(void)
{
	FILE *fpLevCounter;

	// Append "Level2:Initialize" into Output.txt
	fprintf(fp, "Level2:Initialize\n");
	
	// Open file Level2_Counter.txt
	if ((fpLevCounter = fopen("Level2_Counter.txt","r")) == NULL)
	{
		printf("The file Level2_Counter.txt is NULL. \n");
		return;
	}

	// Read
	fscanf(fpLevCounter,"%d",&Level2_Counter);

	fclose(fpLevCounter);
}

void Update2(void)
{
	// Append "Level2:Update" into Output.txt
	fprintf(fp, "Level2:Update\n");

	Level2_Counter -= 1;

	if (Level2_Counter == 0)
	{
		Level2_Lives -= 1;
		
		if (Level2_Lives == 0)
			Next = GS_Quit;
		else
			Next = GS_Restart;
	}
}

void Draw2(void)
{
	// Append "Level2:Draw" into Output.txt
	fprintf(fp, "Level2:Draw\n");
}

void Free2(void)
{
	// Append "Level2:Free" into Output.txt
	fprintf(fp, "Level2:Free\n");
}

void Unload2(void)
{
	// Append "Level2:Unload" into Output.txt
	fprintf(fp, "Level2:Unload\n");
}

//------------------------------------------------------------------------------
// Private Functions:
//------------------------------------------------------------------------------
