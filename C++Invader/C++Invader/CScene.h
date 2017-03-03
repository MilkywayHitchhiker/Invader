#pragma once
#include"stdafx.h"
#include"ScreenBuffer.h"

class CScene
{
protected :
	Buffer_Screen *pScreen = Buffer_Screen::GetInstance ();
public :
	CScene (void)
	{

	}
	~CScene (void)
	{

	}
	virtual void run (void) = 0;
	virtual void Draw (void) = 0;
};