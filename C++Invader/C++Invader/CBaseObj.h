#pragma once
#include"stdafx.h"
#include"ScreenBuffer.h"
#include"Linkedlist.h"

enum Type
{
	EnemyOne = 100,
	EnemyTwo = 105,
	User = 200,
	Bullet = 300
};
enum BType
{
	_TArraw = 1,
	_TWave = 2
};



class CBaseObj
{
protected :
	int PosX;
	int PosY;
	
	//충돌처리를 위한 객체 구별 타입
	Type TYPE;
	int HP;

	Buffer_Screen *pScreen = Buffer_Screen::GetInstance ();
public :

	//해당 객체 정보를 얻기위한 Get함수들
	int GetX (void);
	int GetY (void);
	Type GetType (void);

	//데미지 처리 함수
	void Crash (int Damage);

	//충돌 확인 함수 true일 경우 충돌 false일 경우 아님.
	bool Collision (int x, int y);

	//새로 할당받은 객체를 저장하기 위한 Set함수
	void SetPos (int x, int y, int HitPoint,Type name);

	void Create_Bullet (int x, int y,Type name,BType Bullet);

	virtual bool Action (void) = 0;

	virtual void Draw (void) = 0;
};

extern LinkedList<CBaseObj *> List;
