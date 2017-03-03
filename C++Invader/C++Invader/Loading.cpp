#include"stdafx.h"
#include"Loading.h"
#include"Player.h"
#include"Enemy1.h"
#include<stdlib.h>
#include<time.h>
#define EMax 40


void Loading::run (void)
{
	int x;
	int y;
	int EnY = 1;
	int HP = 2;
	Enemy1 *Enemy;


	int cnt;

	//���� ����
	for ( cnt = 0; cnt < EMax; cnt++ )
	{
		if ( cnt % 10 == 0 && cnt != 0 )
		{
			EnY++;
		}

		x = 16 + (5 * ((cnt % 10) + 1));
		y = 2 + EnY;

		Enemy = new Enemy1 (x, y, HP);
		List.Push_Front (Enemy);
	}
	
	//�Ʊ� ����
	Player *user = new Player (40, 15, 5);
	List.Push_Back (user);


	//���Ͱ� �� �Ѿ� �õ尪 ����
	srand (( unsigned int )time (NULL));

	_pManager->LoadScene (Case_Stage1);
	return;


}
void Loading::Draw (void)
{
	return;
}