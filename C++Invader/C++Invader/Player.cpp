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
	//널문자 제거를 위한 사이즈 -1
	pScreen->Sprite_txt (1, 22, SelectMissle1, sizeof (SelectMissle1) - 1);
	pScreen->Sprite_txt (10, 22, SelectMissle2, sizeof (SelectMissle2) - 1);
	
	//플레이어를 뒤에 Draw함으로써 문자 bar와 곂쳤을 경우 플레이어를 상단에 보여주게 된다.
	pScreen->Sprite_Draw (PosX, PosY, charactor, sizeof (charactor));

	return;
}


void Player::Move_Check (int x, int y)
{
	int chkX = PosX + x;
	int chkY = PosY + y;


	////////////////////////////////////////////////////////////////////////
	//케릭터가 벽에 닿았을 경우 처리
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
	//케릭터가 적군에 닿았을 경우 처리
	///////////////////////////////////////////////////////////////////////
	for ( Iter = List.Begin (); Iter != List.End (); Iter++ )
	{
		Obj = *Iter;

		if (  Obj->GetType () >= EnemyOne && Obj->GetType() <= EnemyTwo )
		{
			//true면 해당 객체와의 충돌이므로 충돌처리를 해준다.
			if ( Obj->Collision(chkX,chkY) )
			{
				Obj->Crash (-1);
				Crash (-1);
				break;
			}
		}
	}

	//모든 충돌처리 및 이동작업 마친후 위치 저장.
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