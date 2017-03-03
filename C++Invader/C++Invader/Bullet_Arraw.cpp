#include"stdafx.h"
#include"Bullet_Arraw.h"



bool Bullet_Arraw::Action (void)
{
	//이동시 벽면 충돌처리
	if ( !Move () )
	{
		return false;
	}


	//해당 총알이 플레이어가 발사한 총알일 경우 리스트를 돌면서 적군 충돌 체크
	if ( BType == User )
	{
		for ( Iter = List.Begin (); Iter != List.End (); Iter++ )
		{
			Obj = *Iter;

			if ( Obj->GetType() == EnemyOne || Obj->GetType() == EnemyTwo )
			{
				//충돌체크 하여 맞으면 체력차감처리 및 총알 삭제
				if ( Obj->Collision (PosX, PosY) )
				{
					Obj->Crash (-1);
					return false;
				}
			}
		}
	}

	//해당 총알이 적군이 발사한 총알일 경우 리스트를 돌면서 유저 충돌 체크
	if ( BType >= EnemyOne && BType <= EnemyTwo )
	{
		for ( Iter = List.Begin (); Iter != List.End(); Iter++ )
		{
			Obj = *Iter;

			if ( Obj->GetType() == User )
			{
				//충돌체크 하여 맞으면 체력차감처리 및 총알 삭제
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

	//상하 벽면에 충돌체크
	if ( PosY < 1 || PosY > dfSCREEN_HEIGHT - 2)
	{
		return false;
	}
	return true;

}