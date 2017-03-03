#pragma once
#include"stdafx.h"
#include"CBaseObj.h"
#include"KeyProcess.h"

class Player :public CBaseObj
{
private:
	char charactor[3] = { '*','^','*' };
	char SelectMissle1[10] = "[1.Arraw]";
	char SelectMissle2[15] = "[2.WaveMissle]";
	int Missle;


	KeyProcess Input;

	LinkedList<CBaseObj *>::Iterator Iter;
	CBaseObj *Obj;

	void Move_Check (int x = 0, int y = 0);
	void Move (int Key);
public :
	Player (int x, int y, int Hitpoint)
	{
		SetPos (x, y, Hitpoint, User);
		Missle = Missle1;
	}
	~Player ()
	{

	}


	bool Action ();
	void Draw ();
};
