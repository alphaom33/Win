#include "GameManager.h"
#include "list"
#include "Print.h"

std::list<TimedCodeBullet*> GameManager::timedListBullet;
std::list<TimedCodeMenu*> GameManager::timedListMenu;
std::list<TimedCodeAlways*> GameManager::timedListAlways;

void GameManager::RegisterTimedCode(TimedCodeBase* timedCode)
{
	timedListAlways.push_back((TimedCodeAlways*)timedCode);
}

void GameManager::RegisterTimedCode(TimedCodeBase* timedCode, State kind) {
	switch (kind) {
	case BULLET:
		timedListBullet.push_back((TimedCodeBullet*)timedCode);
		break;
	case MENU:
		timedListMenu.push_back((TimedCodeMenu*)timedCode);
		break;
	}
}

void GameManager::SetState(State newState)
{
	Exits();
	state = newState;
	Entries();
}

void GameManager::Entries()
{
	switch (state)
	{
	case GameManager::BULLET:
		for (TimedCodeBullet* t : timedListBullet) {
			t->BulletEnter();
		}
		break;
	case GameManager::MENU:
		for (TimedCodeMenu* t : timedListMenu) {
			t->MenuEnter();
		}
		break;
	}
}

void GameManager::Periodics()
{
	for (TimedCodeAlways* t : timedListAlways) {
		t->AlwaysPeriodic();
	}

	switch (state)
	{
	case GameManager::BULLET:
		for (TimedCodeBullet* t : timedListBullet) {
			t->BulletPeriodic();
		}
		break;
	case GameManager::MENU:
		for (TimedCodeMenu* t : timedListMenu) {
			t->MenuPeriodic();
		}
		break;
	}
}

void GameManager::Exits()
{
	switch (state)
	{
	case GameManager::BULLET:
		for (TimedCodeBullet* t : timedListBullet) {
			t->BulletExit();
		}
		break;
	case GameManager::MENU:
		for (TimedCodeMenu* t : timedListMenu) {
			t->MenuExit();
		}
		break;
	}
}

GameManager::State GameManager::state;
