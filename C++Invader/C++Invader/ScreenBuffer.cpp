#include"stdafx.h"
#include"ScreenBuffer.h"
#include<string.h>


//가상모니터에 객체 그리기
void Buffer_Screen::Sprite_Draw (int x, int y, char *p, int Length)
{
	int StartPos = x - Length / 2;
	int Len;

	Len = 0;

	for ( int cntx = StartPos; cntx < StartPos + Length; cntx++ )
	{
		if ( (cntx >= 1 && cntx <= dfSCREEN_WIDTH - 2) && ( y >= 1 && y <= dfSCREEN_HEIGHT-2 ) )
		{
			Screen_Buffer[y][cntx] = p[Len];
		}

		Len++;
	}

	
	
	return;
}

void Buffer_Screen::Sprite_txt (int x, int y, char *p, int Length)
{
	int Len;

	Len = 0;

	for ( int cntx = x; cntx < x + Length; cntx++ )
	{
		if ( (cntx >= 1 && cntx <= dfSCREEN_WIDTH - 2) && (y >= 1 && y <= dfSCREEN_HEIGHT - 2) )
		{
			Screen_Buffer[y][cntx] = p[Len];
		}

		Len++;
	}



	return;
}


//가상모니터 화면을 모니터에 Draw
void Buffer_Screen::Flip (void)
{
	int cnt;

	for ( cnt = 0; cnt < dfSCREEN_HEIGHT; cnt++ )
	{
		cs_MoveCursor (0, cnt);
		printf (Screen_Buffer[cnt]);
	}
	return;
}

//가상모니터 초기화
void Buffer_Screen::Screen_Clear (void)
{
	int y;

	memset (Screen_Buffer, ' ', sizeof (Screen_Buffer));
	for ( y = 0; y < dfSCREEN_HEIGHT; y++ )
	{
		if ( y == 0 || y == dfSCREEN_HEIGHT - 1 )
		{
			memset (Screen_Buffer[y], '*', dfSCREEN_WIDTH - 1);
		}


		Screen_Buffer[y][0] = '*';
		Screen_Buffer[y][dfSCREEN_WIDTH - 2] = '*';
		Screen_Buffer[y][dfSCREEN_WIDTH - 1] = '\0';
	}
	return;
}

