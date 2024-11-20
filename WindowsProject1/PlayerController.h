#include "TimedCodeBullet.h"
#include "Sprite.h"

#pragma once
class PlayerController : TimedCodeBullet
{
public:
	PlayerController(HWND);
	void BulletEnter() override;
	void BulletPeriodic() override;
	void BulletExit() override;
private:
	Sprite* heart;
	HWND hwnd;

};

