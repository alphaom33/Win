#include "GameManager.h"
#include "list"
#include "Print.h"

#include <thread>

State GameManager::state;
int GameManager::count;

std::vector<ITimedCode*> GameManager::timedList;
std::queue<ITimedCode*> GameManager::toFree;

void GameManager::RunTurn(Turn* turn) {
	std::thread(turn->turn).detach();
}

int GameManager::RegisterTimedCode(ITimedCode* timedCode) {
	timedList.push_back(timedCode);
	return count++;
}

void GameManager::UnRegisterTimedCode(ITimedCode* timedCode)
{
	auto index = std::find(timedList.begin(), timedList.end(), timedCode);
	if (index != timedList.end()) {
		timedList.erase(index);
	}
}

void GameManager::QueueUnRegisterTimedCode(ITimedCode* timedCode)
{
	toFree.push(timedCode);
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

	for (int i = 0; i < toFree.size(); i++) {
		UnRegisterTimedCode(toFree.front());
		toFree.front()->OnUnregister();
		toFree.pop();
	}
}

void GameManager::Exits()
{
	for (ITimedCode* t : timedList) {
		if (t->GetState() == state) {
			t->Exit();
		}
	}
}

void GameManager::Reset()
{
	timedList = std::vector<ITimedCode*>();
}
