#include "ButtonManager.h"
#include "InputManager.h"
#include "MoreVK.h"

ButtonManager::ButtonManager(std::vector<Button*> buttons) : TimedCode(State::MENU)
{
	this->buttons = buttons;
	current = 0;

	this->buttons[current]->SetSprite(true);
}

void ButtonManager::Enter()
{
}

void ButtonManager::Periodic()
{
	if (InputManager::GetKeyDown(VK_RIGHT))
	{
		ChangeButton(1);
	}
	else if (InputManager::GetKeyDown(VK_LEFT))
	{
		ChangeButton(-1);
	}
}

void ButtonManager::Exit()
{
	for (Button* b : buttons) {
		b->SetSprite(false);
	}
}

void ButtonManager::ChangeButton(int amount)
{
	buttons[current]->SetSprite(false);

	current += amount;
	current = ((current % buttons.size()) + buttons.size()) % buttons.size();

	buttons[current]->SetSprite(true);
}
