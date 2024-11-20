#include "TimedCodeAlways.h"
#include "GameManager.h"

TimedCodeAlways::TimedCodeAlways()
{
	GameManager::RegisterTimedCode(this, GameManager::State::ALWAYS);
}

void TimedCodeAlways::Periodic()
{
	AlwaysPeriodic();
}
