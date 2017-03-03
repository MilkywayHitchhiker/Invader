#include"stdafx.h"
#include"Bullet_Wave.h"
#include<math.h>


bool Bullet_Wave::Action (void)
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

			if ( Obj->GetType () == EnemyOne || Obj->GetType () == EnemyTwo )
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
		for ( Iter = List.Begin (); Iter != List.End (); Iter++ )
		{
			Obj = *Iter;

			if ( Obj->GetType () == User )
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

void Bullet_Wave::Draw (void)
{
	//Wave Bullet 특성상 맵의 가장자리에서 발사할시 맵을 벗어날 수 있으므로 맵을 벗어날 시 에는 Draw를 안한다.
	if ( PosX >= 1 && PosX <= dfSCREEN_WIDTH - 3 )
	{
		pScreen->Sprite_Draw (PosX, PosY, &Wave, sizeof (Wave));
	}

}


bool Bullet_Wave::Move (void)
{
	//가속도는 선형값.

	//비선형적으로 증가된 X가 Max치에 도달하면 반전 시켜서 비선형적으로 줄어들게 함.
	
 	if ( Wave_Pendulum.pendulum >= CreateX + PendulumMoveMax )
	{
		Wave_Pendulum.MovememtMax = false;
	}
	else if ( Wave_Pendulum.pendulum <= CreateX - PendulumMoveMax )
	{
		Wave_Pendulum.MovememtMax = true;

	}
	else if ( Wave_Pendulum.pendulum == CreateX )
	{
		Wave_Pendulum.MovememtMax = !Wave_Pendulum.MovememtMax;
	}

	//가속도를 계속 누적시켯 속도가 선형적으로 증가하게 함. if는 좌우 극점에 닿았을경우 선형적으로 줄어들게 하기 위한 flag
	if ( Wave_Pendulum.MovememtMax && ( Wave_Pendulum.pendulum != CreateX ) )
	{
		Wave_Pendulum.Movement += Wave_Pendulum.Speed;
	}
	else if ( Wave_Pendulum.pendulum == CreateX )
	{

	}
	else
	{
		Wave_Pendulum.Movement -= Wave_Pendulum.Speed;
	}

	//생성자에서 pendulum에 생성된 X위치를 기억시킴.
	//X위치부터 누적되면서 증가한Movement를 더해서 비선형적으로 증가시킴.
	Wave_Pendulum.pendulum += Wave_Pendulum.Movement;
	


	//진자운동완성.
	PosX = Wave_Pendulum.pendulum;

	if ( BType == User )
	{
		PosY--;
	}
	else if ( BType == EnemyOne || BType == EnemyTwo )
	{
		PosY++;
	}





	//상하 벽면에 충돌체크
	if ( PosY < 1 || PosY > dfSCREEN_HEIGHT - 2 )
	{
		return false;
	}
	return true;

}