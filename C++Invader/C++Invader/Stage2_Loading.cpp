#include"stdafx.h"
#include"Stage2_Loading.h"

#define EMax 40


void Stage2_Loading::run (void)
{

	int Num;

	Key.KeyPros (&Num);

	if ( Num == Attack )
	{
		_pManager->LoadScene (Case_Stage2);
	}
	return;


}
void Stage2_Loading::Draw (void)
{

	pScreen->Screen_Clear ();

	char Top2[57] = "                    Are You Ready?                      ";
	char Top3[57] = "                        Stage2                          ";

	pScreen->Sprite_txt (13, 9, Top2, 56);
	pScreen->Sprite_txt (13, 10, Top3, 56);
	

	pScreen->Flip ();

	return;
}