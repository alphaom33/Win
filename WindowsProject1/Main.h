#include "TimedCode.h"
#include "Sprite.h"

#pragma once
class Main : public TimedCode
{
public:
	Main(HWND);

	// Inherited via TimedCode
	void Periodic() override;
	void Enter() override;
	void Exit() override;
};

