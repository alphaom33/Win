#include "TimedCodeAlways.h"
#include "GameManager.h"

TimedCodeAlways::TimedCodeAlways()
{
	GameManager::RegisterTimedCode(this);
}
