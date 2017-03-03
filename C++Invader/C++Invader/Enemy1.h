#pragma once
#include"stdafx.h"
#include"CBaseObj.h"

#define BulletMax 2
#define EnemyMove 3


class Enemy1 : public CBaseObj
{
private :
	char Enemy_a[3] = { '@','-','@' };

	struct CreateXY
	{
		int X;
		int Y;
	};

	CreateXY Create;
	bool MoveFlag;

	LinkedList<CBaseObj *>::Iterator Iter;
	CBaseObj *Obj;

public :
	Enemy1 (int x, int y, int Hp)
	{
		SetPos (x, y, Hp, EnemyOne);
		Create.X = x;
		Create.Y = y;
	}
	~Enemy1 (void)
	{

	}

	bool Action (void);
	void Draw (void);

	void Move (void);

	void Shot (void);

};