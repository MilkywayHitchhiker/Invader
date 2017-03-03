#pragma once
#include"stdafx.h"
#include"CBaseObj.h"

class Bullet_Arraw : public CBaseObj
{
private :
	char Arraw = 'l';
	char Arraw_Enemy = 'V';
	Type BType;

	LinkedList<CBaseObj *>::Iterator Iter;
	CBaseObj *Obj;

public :
	Bullet_Arraw (int x,int y,Type name)
	{
		PosX = x;
		PosY = y;
		TYPE = Bullet;
		BType = name;
		HP = 1;
	}

	bool Action (void);
	void Draw (void);
	
	bool Move (void);

};