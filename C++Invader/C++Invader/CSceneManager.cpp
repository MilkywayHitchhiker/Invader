#include"stdafx.h"
#include"CSceneManager.h"
#include"Title.h"
#include"Loading.h"
#include"Stage1.h"
#include"Ending.h"
#include"Clear.h"
#include"Stage1_Clear.h"
#include"Stage2_Loading.h"
#include"Stage2.h"

bool CSceneManager::run (void)
{
	//����ȯ�� �� ��ü
	if ( pScene != pSBuffer )
	{
		delete pScene;
		pScene = pSBuffer;
	}
	if ( pScene == NULL )
	{
		return true;
	}

	//��ü�� ������ �۵���Ų��.
	pScene->run ();

	pScene->Draw ();

	return false;
}


//�� �ҷ�����
void CSceneManager::LoadScene (SceneCase SceneType)
{

	switch ( SceneType )
	{
	case Case_Title:
		pSBuffer = new Title (Manager);
		break;
	case Case_Loading:
		pSBuffer = new Loading (Manager);
		break;
	case Case_Stage2Loading:
		pSBuffer = new Stage2_Loading (Manager);
		break;
	case Case_Stage1:
		pSBuffer = new Stage1 (Manager);
		break;
	case Case_Stage2:
		pSBuffer = new Stage2 (Manager);
		break;
	case Case_Ending:
		pSBuffer = new Ending (Manager);
		break;
	case Case_Clear:
		pSBuffer = new Clear (Manager);
		break;
	case Case_Stage1_Clear:
		pSBuffer = new Stage1_Clear (Manager);
		break;
	case Case_End:
		pSBuffer = NULL;
		break;
	}

}