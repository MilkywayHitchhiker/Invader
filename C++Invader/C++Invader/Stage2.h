#pragma once
#include"CScene.h"
#include"CSceneManager.h"
#include"CBaseObj.h"


class Stage2 : public CScene
{
private:
	CSceneManager *_pManager;
	LinkedList<CBaseObj *>::Iterator Iter;
	CBaseObj *Obj;
public:
	Stage2 (CSceneManager *pManager)
	{
		_pManager = pManager;
	}
	~Stage2 (void)
	{

	}
	virtual void run (void);
	virtual void Draw (void);

};