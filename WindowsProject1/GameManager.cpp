#include "GameManager.h"
#include "list"
#include "Print.h"

State GameManager::state;

std::vector<ITimedCode*> GameManager::timedList;

void GameManager::RegisterTimedCode(ITimedCode* timedCode) {
	timedList.push_back(timedCode);
}

void GameManager::SetState(State newState)
{
	Exits();
	state = newState;
	Entries();
}

void GameManager::Entries()
{
	for (ITimedCode* t : timedList) {
		if (t->GetState() == state) t->Enter();
	}
}

void GameManager::Periodics()
{
	for (ITimedCode* t : timedList) {
		if (t->GetState() == state || t->GetState() == State::ALWAYS) t->Periodic();
	}
}

void GameManager::Exits()
{
	for (ITimedCode* t : timedList) {
		if (t->GetState() == state)
		t->Exit();
	}
}
