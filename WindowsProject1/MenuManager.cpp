#include "MenuManager.h"
#include "Drawer.h"
#include "GameManager.h"

Menu* MenuManager::menu;

void MenuManager::InitMenu()
{
	new MenuManager();
}

void MenuManager::SetMenu(Menu* p_menu)
{
	Drawer::UnRegisterText(menu);
	menu = p_menu;
	Drawer::RegisterText(menu);
}

void MenuManager::MenuEnter()
{
}

void MenuManager::MenuPeriodic()
{
}

void MenuManager::MenuExit()
{
	Drawer::UnRegisterText(menu);
}
