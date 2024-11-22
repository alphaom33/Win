#include "TimedCode.h"
#include "GameManager.h"

TimedCode::TimedCode(State state)
{
	this->state = state;
	GameManager::RegisterTimedCode(this);
}

State TimedCode::GetState()
{
	return state;
}
