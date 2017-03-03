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

		//����Ʈ���� ���� ��ü�� �ϳ��� ������ ClearFlag�� falseó����.
		if ( EnemyTwo == Obj->GetType()  && (true == ClearFlag) )
		{
			ClearFlag = false;
		}


		if ( false == Obj->Action () )
		{
			//ü���� 0�� ���°� �������
			if ( User == Obj->GetType () )
			{
				//����Ʈ�� ���鼭 ��� ������Ʈ�� �����ϰ�
				for ( Iter = List.Begin (); Iter != List.End (); Iter++ )
				{
					Obj = *Iter;
					delete Obj;
				}

				//��� ��带 �ı��ѵ� ���������� ��ȯ��.
				List.AllDelete ();
				_pManager->LoadScene (Case_Ending);
				return;

			}


			//�ش� ��ü�� �Ѿ� Ȥ�� Enemy��� �ش� ��ü�� ��常 ����ó��
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

	//ClearFlag�� true��� �ش� ����Ʈ ���� ������ �ϳ��� ���°��� �ǹǷ� Clearó��
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

