#include "TimedCode.h"
#include "Sprite.h"

#pragma once
class Main : TimedCode
{
public:
	Main(HWND);
	void Start();
	void Periodic();
};

