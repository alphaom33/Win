#include "TimedCodeMenu.h"
#include "GameManager.h"

TimedCodeMenu::TimedCodeMenu() : TimedCodeBase()
{
	GameManager::RegisterTimedCode(this, GameManager::MENU);
}
