#pragma once
#include"CScene.h"
#include"CSceneManager.h"

class Ending : public CScene
{
private :
	CSceneManager *_pManager;
public :
	Ending (CSceneManager *Manager)
	{
		_pManager = Manager;
	}
	~Ending (void)
	{

	}
	virtual void run (void);
	virtual void Draw (void);
};