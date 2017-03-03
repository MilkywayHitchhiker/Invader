#include"stdafx.h"
#include"Stage1_Clear.h"
#include"KeyProcess.h"



void Stage1_Clear::run (void)
{
	KeyProcess Key;

	int Num;

	Key.KeyPros (&Num);

	if ( Num == Attack )
	{
		_pManager->LoadScene (Case_Stage2Loading);
	}
	return;
}

void Stage1_Clear::Draw (void)
{

	pScreen->Screen_Clear ();

	char Top1[57] = "========================================================";
	char Top2[57] = "===============   CONGRATURATION   =====================";
	char Top3[57] = "===============    Stage1 Clear    =====================";
	char Top4[57] = "========================================================";

	pScreen->Sprite_txt (13, 8, Top1, 56);
	pScreen->Sprite_txt (13, 9, Top2, 56);
	pScreen->Sprite_txt (13, 10, Top3, 56);
	pScreen->Sprite_txt (13, 11, Top4, 56);

	pScreen->Flip ();

}