#pragma once
#include"CScene.h"
#include"CSceneManager.h"
#include"CBaseObj.h"


class Stage1 : public CScene
{
private:
	CSceneManager *_pManager;
	LinkedList<CBaseObj *>::Iterator Iter;
	CBaseObj *Obj;
public:
	Stage1 (CSceneManager *pManager)
	{
		_pManager = pManager;
	}
	~Stage1 (void)
	{

	}
	virtual void run (void);
	virtual void Draw (void);

};