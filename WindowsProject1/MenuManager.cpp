#include "MenuManager.h"
#include "Windows.h"
#include "InputManager.h"
#include "GameManager.h"

MenuManager::MenuManager(State state) : TimedCode(state)
{
	menu = NULL;
}

void MenuManager::SetMenu(Menu* p_menu)
{
	menu->SetCurrent(false);
	menu = p_menu;
	menu->SetCurrent(true);
}

void MenuManager::Enter()
{
	menu->Enter();
}

void MenuManager::Periodic()
{
	menu->Periodic();
}

void MenuManager::Exit()
{
	menu->Exit();
}
