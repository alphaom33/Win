#include "Sprite.h"
#include "TimedCode.h"

#pragma once
class Death : TimedCode
{
public:
	Death();

private:
	Sprite* sprite;

	// Inherited via TimedCode
	void Enter() override;
	void Periodic() override;
	void Exit() override;
};

