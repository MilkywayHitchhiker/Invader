// C++Invader.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "CSceneManager.h"
#include<Windows.h>


int main()
{
	CSceneManager SceneManager;

	while ( 1 )
	{
		if ( SceneManager.run () )
		{
			return 0;
		}
		Sleep (50);
	}

    return 0;
}

