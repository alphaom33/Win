#include "MenuManager.h"
#include "Drawer.h"
#include "GameManager.h"

Menu* MenuManager::menu;

void MenuManager::SetMenu(Menu* p_menu)
{
	Drawer::UnRegisterText(menu);
	menu = p_menu;
	Drawer::RegisterText(menu);
}

void MenuManager::Enter()
{
}

void MenuManager::Periodic()
{
}

void MenuManager::Exit()
{
	Drawer::UnRegisterText(menu);
}
