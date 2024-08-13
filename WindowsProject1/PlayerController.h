#include "TimedCodeBullet.h"
#include "Sprite.h"

#pragma once
class PlayerController : TimedCodeBullet
{
public:
	PlayerController(HWND);
	void BulletEnter();
	void BulletPeriodic();
	void BulletExit();
private:
	Sprite* heart;
	HWND hwnd;

};

