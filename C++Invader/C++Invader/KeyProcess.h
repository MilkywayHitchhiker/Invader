#pragma once

enum Key
{
	Left = 1,
	Right,
	Up,
	Down,
	LeftDown,
	RightDown,
	LeftUp,
	RightUp,
	Attack,
	Missle1,
	Missle2
};

class KeyProcess
{
private :


public :
	KeyProcess (void)
	{
	}
	~KeyProcess (void)
	{

	}
	//return false떨어지면 메인메뉴로 나가도록 설정할것.
	bool KeyPros (int *Key);
};