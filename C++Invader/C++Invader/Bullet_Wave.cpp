#include"stdafx.h"
#include"Bullet_Wave.h"
#include<math.h>


bool Bullet_Wave::Action (void)
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

			if ( Obj->GetType () == EnemyOne || Obj->GetType () == EnemyTwo )
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
		for ( Iter = List.Begin (); Iter != List.End (); Iter++ )
		{
			Obj = *Iter;

			if ( Obj->GetType () == User )
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

void Bullet_Wave::Draw (void)
{
	//Wave Bullet Ư���� ���� �����ڸ����� �߻��ҽ� ���� ��� �� �����Ƿ� ���� ��� �� ���� Draw�� ���Ѵ�.
	if ( PosX >= 1 && PosX <= dfSCREEN_WIDTH - 3 )
	{
		pScreen->Sprite_Draw (PosX, PosY, &Wave, sizeof (Wave));
	}

}


bool Bullet_Wave::Move (void)
{
	//���ӵ��� ������.

	//���������� ������ X�� Maxġ�� �����ϸ� ���� ���Ѽ� ���������� �پ��� ��.
	
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

	//���ӵ��� ��� �������� �ӵ��� ���������� �����ϰ� ��. if�� �¿� ������ �������� ���������� �پ��� �ϱ� ���� flag
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

	//�����ڿ��� pendulum�� ������ X��ġ�� ����Ŵ.
	//X��ġ���� �����Ǹ鼭 ������Movement�� ���ؼ� ���������� ������Ŵ.
	Wave_Pendulum.pendulum += Wave_Pendulum.Movement;
	


	//���ڿ�ϼ�.
	PosX = Wave_Pendulum.pendulum;

	if ( BType == User )
	{
		PosY--;
	}
	else if ( BType == EnemyOne || BType == EnemyTwo )
	{
		PosY++;
	}





	//���� ���鿡 �浹üũ
	if ( PosY < 1 || PosY > dfSCREEN_HEIGHT - 2 )
	{
		return false;
	}
	return true;

}