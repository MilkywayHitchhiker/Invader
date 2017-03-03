#include"stdafx.h"
#include"Enemy1.h"
#include<stdlib.h>

bool Enemy1::Action (void)
{

	if ( HP == 0 )
	{
		return false;
	}

	//이동처리
	Move ();

	//총알발사
	Shot ();

	return true;
}
void Enemy1::Draw (void)
{
	pScreen->Sprite_Draw (PosX, PosY, Enemy_a, sizeof (Enemy_a));

	return;
}

void Enemy1::Move (void)
{
	//Enemy의 이동범위 체크해서 범위끝에 도달하면 반대방향으로 이동하도록 함.
	if ( PosX == (Create.X + EnemyMove) || PosX == (Create.X - EnemyMove) )
	{
		MoveFlag = !MoveFlag;
	}

	//이동처리
	if ( MoveFlag == true )
	{
		PosX++;
	}
	else 
	{
		PosX--;
	}
	return;
}


void Enemy1::Shot (void)
{
	int Num;
	
	Num = rand() % 100;
	if ( Num < BulletMax )
	{
		Create_Bullet (PosX, PosY, TYPE, _TArraw);
	}
	return;
}
