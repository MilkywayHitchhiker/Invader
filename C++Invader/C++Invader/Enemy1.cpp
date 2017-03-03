#include"stdafx.h"
#include"Enemy1.h"
#include<stdlib.h>

bool Enemy1::Action (void)
{

	if ( HP == 0 )
	{
		return false;
	}

	//�̵�ó��
	Move ();

	//�Ѿ˹߻�
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
	//Enemy�� �̵����� üũ�ؼ� �������� �����ϸ� �ݴ�������� �̵��ϵ��� ��.
	if ( PosX == (Create.X + EnemyMove) || PosX == (Create.X - EnemyMove) )
	{
		MoveFlag = !MoveFlag;
	}

	//�̵�ó��
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
