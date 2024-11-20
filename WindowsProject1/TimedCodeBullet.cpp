#include "TimedCodeBullet.h"
#include "GameManager.h"
#include "Windows.h"
#include "map"

TimedCodeBullet::TimedCodeBullet() : TimedCodeBase()
{
	GameManager::RegisterTimedCode(this, GameManager::BULLET);
}

void TimedCodeBullet::Enter()
{
	BulletEnter();
}

void TimedCodeBullet::Periodic()
{
	BulletPeriodic();
}

void TimedCodeBullet::Exit()
{
	BulletExit();
}
