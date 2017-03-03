#pragma once
#include"CScene.h"
#include"CSceneManager.h"



class Clear : public CScene
{
private:
	CSceneManager *_pManager;
public:
	Clear (CSceneManager *Manager)
	{
		_pManager = Manager;
	}
	~Clear (void)
	{

	}
	virtual void run (void);
	virtual void Draw (void);
};