#include"stdafx.h"
#include"KeyProcess.h"
#include<Windows.h>



bool KeyProcess::KeyPros (int *Key)
{
	int KeyMessage = 0;

	/*=============================
	4방향 입력키 검사
	=============================*/
	if ( GetAsyncKeyState (VK_UP) & 0x8001 )
	{
		KeyMessage = Up;
	}
	if ( GetAsyncKeyState (VK_DOWN) & 0x8001 )
	{
		KeyMessage = Down;
	}
	if ( GetAsyncKeyState (VK_LEFT) & 0x8001 )
	{
		KeyMessage = Left;
	}
	if ( GetAsyncKeyState (VK_RIGHT) & 0x8001 )
	{
		KeyMessage = Right;
	}
	/*=============================
	대각선 방향 입력키 검사
	=============================*/
	if ( (GetAsyncKeyState (VK_UP) & 0x8001) && (GetAsyncKeyState (VK_LEFT) & 0x8001) )
	{
		KeyMessage = LeftUp;
	}
	if ( (GetAsyncKeyState (VK_UP) & 0x8001) && (GetAsyncKeyState (VK_RIGHT) & 0x8001) )
	{
		KeyMessage = RightUp;
	}
	if ( (GetAsyncKeyState (VK_RIGHT) & 0x8001) && (GetAsyncKeyState (VK_DOWN) & 0x8001) )
	{
		KeyMessage = RightDown;
	}
	if ( (GetAsyncKeyState (VK_DOWN) & 0x8001) && (GetAsyncKeyState (VK_LEFT) & 0x8001) )
	{
		KeyMessage = LeftDown;
	}
	if ( (GetAsyncKeyState (0x31) & 0x8001) )
	{
		KeyMessage = Missle1;
	}
	if ( (GetAsyncKeyState (0x32) & 0x8001) )
	{
		KeyMessage = Missle2;
	}
	if ( (GetAsyncKeyState (VK_SPACE) & 0x8001) )
	{
		KeyMessage = Attack;
	}
	if ( (GetAsyncKeyState ('0') & 0x8001) )
	{
		return false;
	}


	*Key = KeyMessage;

	fflush (stdin);

	return true;
}