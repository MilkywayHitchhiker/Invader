#include"stdafx.h"
#include"Bullet_Arraw.h"



bool Bullet_Arraw::Action (void)
{
	//�̵��� ���� �浹ó��
	if ( !Move () )
	{
		return false;
	}


	//�ش� �Ѿ��� �÷��̾ �߻��� �Ѿ��� ��� ����Ʈ�� ���鼭 ���� �浹 üũ
	if ( BType == User )
	{
		for ( Iter = List.Begin (); Iter != List.End (); Iter++ )
		{
			Obj = *Iter;

			if ( Obj->GetType() == EnemyOne || Obj->GetType() == EnemyTwo )
			{
				//�浹üũ �Ͽ� ������ ü������ó�� �� �Ѿ� ����
				if ( Obj->Collision (PosX, PosY) )
				{
					Obj->Crash (-1);
					return false;
				}
			}
		}
	}

	//�ش� �Ѿ��� ������ �߻��� �Ѿ��� ��� ����Ʈ�� ���鼭 ���� �浹 üũ
	if ( BType >= EnemyOne && BType <= EnemyTwo )
	{
		for ( Iter = List.Begin (); Iter != List.End(); Iter++ )
		{
			Obj = *Iter;

			if ( Obj->GetType() == User )
			{
				//�浹üũ �Ͽ� ������ ü������ó�� �� �Ѿ� ����
				if ( Obj->Collision (PosX, PosY) )
				{
					Obj->Crash (-1);
					return false;
				}
			}
		}
	}
	return true;
}

void Bullet_Arraw::Draw (void)
{
	if ( BType == User )
	{
		pScreen->Sprite_Draw (PosX, PosY, &Arraw, sizeof (Arraw));
	}
	else if ( BType == EnemyOne || BType == EnemyTwo)
	{
		pScreen->Sprite_Draw (PosX, PosY, &Arraw_Enemy, sizeof (Arraw));
	}
}


bool Bullet_Arraw::Move (void)
{
	if ( BType == User )
	{
		PosY--;
	}
	else if ( BType == EnemyOne || BType == EnemyTwo)
	{
		PosY++;
	}

	//���� ���鿡 �浹üũ
	if ( PosY < 1 || PosY > dfSCREEN_HEIGHT - 2)
	{
		return false;
	}
	return true;

}