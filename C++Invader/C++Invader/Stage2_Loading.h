#pragma once
#include"CScene.h"
#include"CSceneManager.h"
#include"CBaseObj.h"
#include"KeyProcess.h"
#include"Player.h"
#include"Enemy1.h"
#include"Enemy2.h"
#include<stdlib.h>
#include<time.h>


class Stage2_Loading : public CScene
{
private:
	CSceneManager *_pManager;
	LinkedList<CBaseObj *>::Iterator Iter;
	CBaseObj *Obj;
	KeyProcess Key;



public:
	Stage2_Loading (CSceneManager *pManager)
	{
		int HP = 2;
		Enemy2 *Boss;


		Boss = new Enemy2 (41, 3, 50);
		List.Push_Front (Boss);


		//아군 셋팅
		Player *user = new Player (40, 15, 5);
		List.Push_Front (user);


		//몬스터가 쏠 총알 시드값 생성
		srand (( unsigned int )time (NULL));

		_pManager = pManager;
	}
	~Stage2_Loading (void)
	{

	}
	virtual void run (void);
	virtual void Draw (void);
};