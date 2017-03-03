#include"stdafx.h"
#include"Stage2.h"
#include"CBaseObj.h"

void Stage2::run (void)
{
	bool ClearFlag = true;
	bool DelFlag = true;

	for ( Iter = List.Begin (); Iter != List.End ();)
	{
		Obj = *Iter;

		//리스트내에 적군 객체가 하나라도 있으면 ClearFlag는 false처리됨.
		if ( EnemyTwo == Obj->GetType()  && (true == ClearFlag) )
		{
			ClearFlag = false;
		}


		if ( false == Obj->Action () )
		{
			//체력이 0인 상태가 유저라면
			if ( User == Obj->GetType () )
			{
				//리스트를 돌면서 모든 오브젝트를 삭제하고
				for ( Iter = List.Begin (); Iter != List.End (); Iter++ )
				{
					Obj = *Iter;
					delete Obj;
				}

				//모든 노드를 파괴한뒤 엔딩씬으로 전환함.
				List.AllDelete ();
				_pManager->LoadScene (Case_Ending);
				return;

			}


			//해당 객체가 총알 혹은 Enemy라면 해당 객체와 노드만 삭제처리
			delete Obj;
			List.Delete (Iter);
			DelFlag = false;
		}

		if ( DelFlag )
		{
			Iter++;
		}
		DelFlag = true;;

	}

	//ClearFlag가 true라면 해당 리스트 내에 적군이 하나도 없는것이 되므로 Clear처리
	if ( ClearFlag )
	{
		for ( Iter = List.Begin (); Iter != List.End (); Iter++ )
		{
			delete *Iter;
		}

		List.AllDelete ();
		_pManager->LoadScene (Case_Clear);
	}


	return;
}

void Stage2::Draw (void)
{
	pScreen->Screen_Clear ();


	for ( Iter = List.Begin (); Iter != List.End (); Iter++ )
	{
		Obj = *Iter;
		Obj->Draw ();
	}
	pScreen->Flip ();
	return;
}

