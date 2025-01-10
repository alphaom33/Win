#include <thread>
#include <list>

#include "GameManager.h"
#include "Print.h"
#include "InputManager.h"

State GameManager::state;

std::vector<ITimedCode*> GameManager::timedList;
std::queue<ITimedCode*> GameManager::toFree;
std::queue<ITimedCode*> GameManager::toAdd;

HWND GameManager::hwnd;
bool goAway = false;

void GameManager::RunTurn(Turn* turn) {
	std::thread(turn->turn).detach();
}

void GameManager::Setup(HWND p_hwnd)
{
	srand(0);
	hwnd = p_hwnd;
}

void GameManager::RegisterTimedCode(ITimedCode* timedCode) {
	toAdd.push(timedCode);
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
	int _ = rand();
	for (ITimedCode* t : timedList) {
		if (t->GetState() == state || t->GetState() == State::ALWAYS) {
			t->Periodic();
		}
	}

	while (toFree.size()) {
		UnRegisterTimedCode(toFree.front());
		toFree.front()->OnUnregister();
		toFree.pop();
	}

	while (toAdd.size()) {
		timedList.push_back(toAdd.front());
		toAdd.pop();
	}

	if (goAway) {
		for (ITimedCode* t : timedList) {
			UnRegisterTimedCode(t);
		}
		goAway = false;
		timedList.clear();
		SendMessage(hwnd, WM_RESET, NULL, NULL);
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
	goAway = true;
}
