#pragma once
#include"stdafx.h"
#include"CScene.h"

enum SceneCase
{
	Case_Title = 1000,
	Case_Loading = 2000,
	Case_Stage2Loading = 2010,
	Case_Stage1 = 3000,
	Case_Stage2 = 3010,
	Case_Ending = 4000,
	Case_Clear = 5000,
	Case_Stage1_Clear = 5010,
	Case_End = 10000
};

class CSceneManager
{
private :

	CSceneManager *Manager;
	CScene *pScene;
	CScene *pSBuffer;

public :
	CSceneManager (void)
	{
		Manager = this;
		LoadScene (Case_Title);



	}
	~CSceneManager (void)
	{

	}
	bool run (void);

	void LoadScene (SceneCase SceneType);
	

};