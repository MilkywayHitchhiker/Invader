#pragma once
#include"stdafx.h"
#include"CBaseObj.h"
#include<stdlib.h>

#define PendulumMoveMax 6

class Bullet_Wave : public CBaseObj
{
private:
	char Wave = 'o';
	Type BType;
	int CreateX;
	int CreateY;

	LinkedList<CBaseObj *>::Iterator Iter;
	CBaseObj *Obj;

	struct WaveForm
	{
		int Speed;
		int Movement;
		bool MovememtMax;
		int pendulum;
	};
	WaveForm Wave_Pendulum;

public:
	Bullet_Wave (int x, int y, Type name)
	{
		PosX = x;
		PosY = y;
		TYPE = Bullet;
		BType = name;
		HP = 1;



		CreateX = x;
		CreateY = y;
		Wave_Pendulum.pendulum = CreateX;

		int direction;
		direction = rand () % 2;


		Wave_Pendulum.Speed = 1;
		if ( direction == 0 )
		{

			Wave_Pendulum.MovememtMax = true;
			Wave_Pendulum.Movement = PendulumMoveMax / 2;
		}
		else
		{
			Wave_Pendulum.MovememtMax = false;
			Wave_Pendulum.Movement = -(PendulumMoveMax / 2);
		}
	}

	bool Action (void);
	void Draw (void);

	bool Move (void);

};