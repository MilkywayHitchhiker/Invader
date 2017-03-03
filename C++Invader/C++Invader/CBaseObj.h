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
	
	//�浹ó���� ���� ��ü ���� Ÿ��
	Type TYPE;
	int HP;

	Buffer_Screen *pScreen = Buffer_Screen::GetInstance ();
public :

	//�ش� ��ü ������ ������� Get�Լ���
	int GetX (void);
	int GetY (void);
	Type GetType (void);

	//������ ó�� �Լ�
	void Crash (int Damage);

	//�浹 Ȯ�� �Լ� true�� ��� �浹 false�� ��� �ƴ�.
	bool Collision (int x, int y);

	//���� �Ҵ���� ��ü�� �����ϱ� ���� Set�Լ�
	void SetPos (int x, int y, int HitPoint,Type name);

	void Create_Bullet (int x, int y,Type name,BType Bullet);

	virtual bool Action (void) = 0;

	virtual void Draw (void) = 0;
};

extern LinkedList<CBaseObj *> List;
