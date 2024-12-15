#include "IBullet.h"
#include "Sprite.h"
#include "TimedCode.h"

#pragma once
class PointerBullet : TimedCode, public IBullet
{
public:
	PointerBullet();

private:
	Sprite* sprite;

	// Inherited via IBullet
	void SetPos(Vector2* pos) override;
public:

	// Inherited via TimedCode
	void Enter() override;
	void Periodic() override;
	void Exit() override;
};

