#include "FleeMenu.h"
#include "GameManager.h"

int time = 0;

FleeMenu::FleeMenu() : Menu(L"you fleed")
{
}

void FleeMenu::Periodic()
{
	time++;
	if (time > 100) {
		GameManager::SetState(State::ENEMY);
	}
}
