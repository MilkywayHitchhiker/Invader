#include"stdafx.h"
#include"CBaseObj.h"
#include"Bullet_Arraw.h"
#include"Bullet_Wave.h"



int CBaseObj::GetX (void)
{
	return PosX;
}
int CBaseObj::GetY (void)
{
	return PosY;
}
Type CBaseObj::GetType (void)
{
	return TYPE;
}
void CBaseObj::SetPos (int x, int y, int HitPoint, Type name)
{
	PosX = x;
	PosY = y;
	HP = HitPoint;
	TYPE = name;
	return;
}

bool CBaseObj::Collision (int x, int y)
{
	if ( PosX == x && PosY == y )
	{
		return true;
	}
	return false;
}


//ÃÑ¾Ë»ý¼º
void CBaseObj::Create_Bullet (int x, int y, Type name, BType Bullet)
{

	if ( Bullet == _TArraw )
	{
		Bullet_Arraw *pArraw = new Bullet_Arraw (x, y, name);
		List.Push_Back (pArraw);
	}
	else if ( Bullet == _TWave )
	{
		Bullet_Wave *pWave = new Bullet_Wave (x, y, name);
		List.Push_Back (pWave);
	}
	return;
}


void CBaseObj::Crash (int Damage)
{
	HP = HP + Damage;
	return;
}

LinkedList<CBaseObj *> List;
LinkedList<CBaseObj *>::Iterator Iter;