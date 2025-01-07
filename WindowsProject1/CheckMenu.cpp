#include "CheckMenu.h"
#include "InputManager.h"
#include "GameManager.h"

#include <format>

CheckMenu::CheckMenu(int atk, int def, std::wstring desc) : TimedCode(State::CHECK), Menu(std::format(
	L"ATK: {0} DEF: {1}\n"
	"{2}",
	atk, def, desc).c_str()) { }

void CheckMenu::Enter()
{
}

void CheckMenu::Periodic()
{
	if (InputManager::GetKeyDown(VK_Z) || InputManager::GetKeyDown(VK_X)) {
		GameManager::SetState(State::ENEMY);
	}
}

void CheckMenu::Exit()
{
	SetCurrent(false);
	GameManager::QueueUnRegisterTimedCode(this);
}

void CheckMenu::OnUnregister()
{
	delete this;
}
