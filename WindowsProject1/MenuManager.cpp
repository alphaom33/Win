#include "MenuManager.h"
#include "GameManager.h"

Menu* MenuManager::menu;

void MenuManager::SetMenu(Menu* p_menu)
{
	menu->SetNotCurrent();
	menu = p_menu;
	menu->SetCurrent();
}
