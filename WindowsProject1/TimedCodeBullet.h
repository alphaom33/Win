#include "TimedCodeBase.h"
#include "Windows.h"

#pragma once
class TimedCodeBullet : TimedCodeBase {
public:
	TimedCodeBullet();

	virtual void BulletEnter() = 0;
	virtual void BulletPeriodic() = 0;
	virtual void BulletExit() = 0;
};
