#include "TimedCodeMenu.h"
#include "GameManager.h"

TimedCodeMenu::TimedCodeMenu() : TimedCodeBase()
{
	GameManager::RegisterTimedCode(this, GameManager::MENU);
}

void TimedCodeMenu::Enter()
{
	MenuEnter();
}

void TimedCodeMenu::Periodic()
{
	MenuPeriodic();
}

void TimedCodeMenu::Exit()
{
	MenuExit();
}
