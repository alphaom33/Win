#include "TimedCode.h"
#include "Sprite.h"

#pragma once
class PlayerController : TimedCode
{
public:
	PlayerController(HWND);
	void Enter() override;
	void Periodic() override;
	void Exit() override;
private:
	Sprite* heart;
	HWND hwnd;

};

