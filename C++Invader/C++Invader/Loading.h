#pragma once
#include"CScene.h"
#include"CSceneManager.h"
#include"CBaseObj.h"



class Loading : public CScene
{
private :
	CSceneManager *_pManager;
	LinkedList<CBaseObj *>::Iterator Iter;
	CBaseObj *Obj;
public :
	Loading (CSceneManager *pManager)
	{
		_pManager = pManager;
	}
	~Loading (void)
	{

	}
	virtual void run (void);
	virtual void Draw (void);
};