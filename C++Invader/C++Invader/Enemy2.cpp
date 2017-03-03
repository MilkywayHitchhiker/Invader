#include"stdafx.h"
#include"Enemy2.h"
#include<stdlib.h>

bool Enemy2::Action (void)
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
void Enemy2::Draw (void)
{
	//널문자 제거를 위해서 사이즈는 sizeof -1 을 한다.
	pScreen->Sprite_Draw (PosX, PosY, Enemy_B, sizeof (Enemy_B) -1 );

	return;
}

void Enemy2::Move (void)
{
	int Num;


	//Enemy의 이동범위 체크해서 범위끝에 도달하면 반대방향으로 이동하도록 함.
	if ( PosX <= MinX || PosX >= MaxX || PosY <= MinY || PosY >= MaxY )
	{
		if ( PosX <= MinX )
		{
			PosX++;
		}
		else if ( PosX >= MaxX )
		{
			PosX--;
		}

		if ( PosY <= MinY )
		{
			PosY++;
		}
		else if ( PosY >= MaxY )
		{
			PosY--;
		}
		return;
	}



	Num = rand () % 100;

	//100을 8개로 쪼개서 랜덤한 8방향 이동처리
	if ( Num < 12 )	//LEFT
	{
		PosX--;
	}
	// Right
	else if ( Num < 24 )
	{
		PosX++;
	}
	// Up
	else if ( Num < 36 )
	{
		PosY--;
	}
	// Down
	else if ( Num < 48 )
	{
		PosY++;
	}
	// LeftUp
	else if ( Num < 60 )
	{
		PosX--;
		PosY--;
	}
	// RightUP
	else if ( Num < 72 )
	{
		PosX++;
		PosY--;
	}
	// Right Down
	else if ( Num < 84 )
	{
		PosX++;
		PosY++;
	}
	// LeftDown
	else if ( Num < 96 )
	{
		PosX--;
		PosY++;
	}
	//Hold
	else
	{
		PosX;
		PosY;
	}

	return;
}


void Enemy2::Shot (void)
{
	int Num;

	Num = rand () % 1000;
	if ( Num < BulletMax )
	{
		Create_Bullet (PosX, PosY, TYPE, _TArraw);
	}
	else if ( Num < BulletSubMax + BulletMax )
	{

		Create_Bullet (PosX, PosY, TYPE, _TWave);
	}
	return;
}
