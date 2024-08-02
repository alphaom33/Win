#include "TimedCode.h"
#include "Sprite.h"

#pragma once
class PlayerController : TimedCode
{
public:
	PlayerController(HWND);
	void Start();
	void Periodic();
private:
	Sprite* heart;
	HWND hwnd;

};

