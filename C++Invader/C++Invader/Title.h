#pragma once
#include"CScene.h"
#include"CSceneManager.h"
#include"KeyProcess.h"

class Title : public CScene
{
private :
	CSceneManager *_pManager;
	KeyProcess Input;
	
	char Selectcharactor[3] = "->";
	int x;
	int y;

public :
	Title (CSceneManager *pManager)
	{
		x = 31;
		y = 13;
		_pManager = pManager;
	}
	~Title (void)
	{

	}
	virtual void run (void);
	virtual void Draw (void);

};