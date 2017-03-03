#pragma once
#include"stdafx.h"
#include"Console.h"

class Buffer_Screen
{
private:
	Buffer_Screen (void)
	{
		cs_Initial ();
		Screen_Clear ();
	}



	char Screen_Buffer[dfSCREEN_HEIGHT][dfSCREEN_WIDTH];



public:
	~Buffer_Screen ()
	{

	}

	static Buffer_Screen *GetInstance (void)
	{
		static Buffer_Screen Instance;
		return &Instance;
	}



	//�������Ϳ� ��ü �׸���
	void Sprite_Draw (int x, int y, char *p,int Size);	

	//�������Ϳ� ���� ����ϱ�
	void Sprite_txt (int x, int y, char *p, int Size);	

	//�������� ȭ���� ����Ϳ� Draw
	void Flip (void);			

	//�������� �ʱ�ȭ
	void Screen_Clear (void);								
};	