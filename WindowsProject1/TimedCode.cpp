#include "TimedCode.h"
#include "GameManager.h"

TimedCode::TimedCode(State state)
{
	this->state = state;
	id = GameManager::RegisterTimedCode(this);
}

State TimedCode::GetState()
{
	return state;
}

int TimedCode::GetID() {
	return id;
}
