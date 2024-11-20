#include "GameManager.h"
#include "list"
#include "Print.h"

GameManager::State GameManager::state;

std::map<GameManager::State, std::vector<TimedCodeBase*>> GameManager::timedLists;

void GameManager::RegisterTimedCode(TimedCodeBase* timedCode, State kind) {
	if (!timedLists.count(kind)) {
		timedLists[kind] = std::vector<TimedCodeBase*>();
	}
	timedLists[kind].push_back(timedCode);
}

void GameManager::SetState(State newState)
{
	Exits();
	state = newState;
	Entries();
}

void GameManager::Entries()
{
	for (TimedCodeBase* t : timedLists[state]) {
		t->Enter();
	}
}

void GameManager::Periodics()
{
	for (TimedCodeBase* t : timedLists[State::ALWAYS]) {
		t->Periodic();
	}
	for (TimedCodeBase* t : timedLists[state]) {
		t->Periodic();
	}
}

void GameManager::Exits()
{
	for (TimedCodeBase* t : timedLists[state]) {
		t->Exit();
	}
}
