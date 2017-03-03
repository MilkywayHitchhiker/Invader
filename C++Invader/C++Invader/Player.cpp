#include"stdafx.h"
#include"Player.h"
#include"KeyProcess.h"


bool Player::Action(void)
{
	int Key;
	
	if ( false == Input.KeyPros (&Key) || HP == 0)
	{
		return false;
	}

	if ( Key == Missle1 || Key == Missle2 )
	{
		Missle = Key;
	}


	if ( Key >= Left && Key <= RightUp )
	{
		Move (Key);
	}
	else if ( Key == Attack )
	{
		if ( Missle == Missle1 )
		{
			Create_Bullet (PosX, PosY, TYPE, _TArraw);
		}
		else if ( Missle == Missle2 )
		{
			Create_Bullet (PosX, PosY, TYPE, _TWave);
		}
	}



	return true;
}

void Player::Draw (void)
{
	//�ι��� ���Ÿ� ���� ������ -1
	pScreen->Sprite_txt (1, 22, SelectMissle1, sizeof (SelectMissle1) - 1);
	pScreen->Sprite_txt (10, 22, SelectMissle2, sizeof (SelectMissle2) - 1);
	
	//�÷��̾ �ڿ� Draw�����ν� ���� bar�� ������ ��� �÷��̾ ��ܿ� �����ְ� �ȴ�.
	pScreen->Sprite_Draw (PosX, PosY, charactor, sizeof (charactor));

	return;
}


void Player::Move_Check (int x, int y)
{
	int chkX = PosX + x;
	int chkY = PosY + y;


	////////////////////////////////////////////////////////////////////////
	//�ɸ��Ͱ� ���� ����� ��� ó��
	///////////////////////////////////////////////////////////////////////
	if ( chkX < 1 )
	{
		chkX = 1;
	}
	else if ( chkX > dfSCREEN_WIDTH - 3 )
	{
		chkX = dfSCREEN_WIDTH - 3;
	}
	if ( chkY < 1 )
	{
		chkY = 1;
	}
	else if ( chkY > dfSCREEN_HEIGHT - 2 )
	{
		chkY = dfSCREEN_HEIGHT - 2;
	}

	////////////////////////////////////////////////////////////////////////
	//�ɸ��Ͱ� ������ ����� ��� ó��
	///////////////////////////////////////////////////////////////////////
	for ( Iter = List.Begin (); Iter != List.End (); Iter++ )
	{
		Obj = *Iter;

		if (  Obj->GetType () >= EnemyOne && Obj->GetType() <= EnemyTwo )
		{
			//true�� �ش� ��ü���� �浹�̹Ƿ� �浹ó���� ���ش�.
			if ( Obj->Collision(chkX,chkY) )
			{
				Obj->Crash (-1);
				Crash (-1);
				break;
			}
		}
	}

	//��� �浹ó�� �� �̵��۾� ��ģ�� ��ġ ����.
	PosX = chkX;
	PosY = chkY;
	return;
}

void Player::Move (int Key)
{
	switch ( Key )
	{
	case Left:
		Move_Check (-1, 0);
		break;

	case Right:
		Move_Check (1, 0);
		break;

	case Up:
		Move_Check (0, -1);
		break;

	case Down:
		Move_Check (0, 1);
		break;

	case LeftDown:
		Move_Check (-1, 1);
		break;

	case RightDown:
		Move_Check (1, 1);
		break;

	case LeftUp:
		Move_Check (-1, -1);
		break;

	case RightUp:
		Move_Check (1, -1);
		break;
	}

	return;
}