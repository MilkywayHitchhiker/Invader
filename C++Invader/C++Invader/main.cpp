// C++Invader.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
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

