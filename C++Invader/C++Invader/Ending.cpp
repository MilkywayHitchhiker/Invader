#include"stdafx.h"
#include"Ending.h"
#include"KeyProcess.h"

void Ending::run (void)
{
	KeyProcess Key;

	int Num;

	Key.KeyPros (&Num);
	
	if ( Num == Attack )
	{
		_pManager->LoadScene (Case_Title);
	}
	return;
}

void Ending::Draw (void)
{

	pScreen->Screen_Clear ();

	char Top1[57] = "Y   Y  OOO  U   U   AA  RRRR  EEEE  DDD  EEEE  AA  DDD  ";
	char Top2[57] = " Y Y  O   O U   U  A  A R   R E     D  D E    A  A D  D ";
	char Top3[57] = "  Y   O   O U   U  AAAA RRRR  EEE   D  D EEE  AAAA D  D ";
	char Top4[57] = "  Y   O   O U   U  A  A R R   E     D  D E    A  A D  D ";
	char Top5[57] = "  Y    OOO   UUU   A  A R  RR EEEE  DDD  EEEE A  A DDD  ";

	pScreen->Sprite_txt (13, 8, Top1, 56);
	pScreen->Sprite_txt (13, 9, Top2, 56);
	pScreen->Sprite_txt (13, 10, Top3, 56);
	pScreen->Sprite_txt (13, 11, Top4, 56);
	pScreen->Sprite_txt (13, 12, Top5, 56);

	pScreen->Flip ();

}