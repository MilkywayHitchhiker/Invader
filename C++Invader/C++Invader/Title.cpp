#include"stdafx.h"
#include"Title.h"


void Title::run (void)
{
	int Key;

	Input.KeyPros (&Key);

	if ( Key == Up && y == 15)
	{
		y = 13;
	}
	else if ( Key == Down && y == 13)
	{
		y = 15;
	}

	//Attack SpaceKey
	if ( Key == Attack )
	{
		if ( y == 15 )
		{
			_pManager->LoadScene (Case_End);
		}

		if ( y == 13 )
		{
			_pManager->LoadScene (Case_Loading);
		}
	}

}

void Title::Draw (void)
{

	pScreen->Screen_Clear ();

	char name[14] = "I N V A D E R";
	char menu1[12] = "1.GameStart";
	char menu2[6] = "2.End";


	pScreen->Sprite_txt (34,8,name,13);
	pScreen->Sprite_txt (34, 13, menu1, 11);
	pScreen->Sprite_txt (34, 15, menu2, 5);
	pScreen->Sprite_txt (x, y, Selectcharactor, 2);

	pScreen->Flip ();
	return;
}