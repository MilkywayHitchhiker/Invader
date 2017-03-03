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



	//가상모니터에 객체 그리기
	void Sprite_Draw (int x, int y, char *p,int Size);	

	//가상모니터에 글자 출력하기
	void Sprite_txt (int x, int y, char *p, int Size);	

	//가상모니터 화면을 모니터에 Draw
	void Flip (void);			

	//가상모니터 초기화
	void Screen_Clear (void);								
};	