#pragma once
#include"stdafx.h"
#include"CBaseObj.h"

#define BulletMax 200
#define BulletSubMax 50
enum MoveMax
{
	MinX = 2,
	MinY = 2,
	MaxX = dfSCREEN_WIDTH -3,
	MaxY = 14
};


class Enemy2 : public CBaseObj
{
private:
	char Enemy_B[6] = "(*_*)";

	struct CreateXY
	{
		int X;
		int Y;
	};

	CreateXY Create;
	bool MoveFlag;

	LinkedList<CBaseObj *>::Iterator Iter;
	CBaseObj *Obj;

public:
	Enemy2 (int x, int y, int Hp)
	{
		SetPos (x, y, Hp, EnemyTwo);
		Create.X = x;
		Create.Y = y;
	}
	~Enemy2 (void)
	{

	}

	bool Action (void);
	void Draw (void);

	void Move (void);

	void Shot (void);

	

};