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
	//return false�������� ���θ޴��� �������� �����Ұ�.
	bool KeyPros (int *Key);
};