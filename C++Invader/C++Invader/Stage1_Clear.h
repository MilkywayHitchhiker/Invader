#pragma once
#include"CScene.h"
#include"CSceneManager.h"



class Stage1_Clear : public CScene
{
private:
	CSceneManager *_pManager;
public:
	Stage1_Clear (CSceneManager *Manager)
	{
		_pManager = Manager;
	}
	~Stage1_Clear (void)
	{

	}
	virtual void run (void);
	virtual void Draw (void);
};