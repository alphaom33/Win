#include "ButtonManager.h"
#include "InputManager.h"
#include "MoreVK.h"
#include "GameManager.h"

ButtonManager::ButtonManager(std::vector<IButton*> buttons, bool alwaysShowing, State state) : TimedCode(state)
{
	this->buttons = buttons;
	current = 0;

	this->buttons[current]->SetSprite(true);
	this->alwaysShowing = alwaysShowing;
	if (alwaysShowing) 
	{
		for (auto b : buttons) 
		{
			b->Register();
		}
	}
}

ButtonManager::~ButtonManager()
{
	for (int i = 0; i < buttons.size(); i++)
	{
		buttons[i]->UnRegister();
	}
	buttons.clear();
	GameManager::UnRegisterTimedCode(this);
}

void ButtonManager::Enter()
{
	if (!alwaysShowing) 
	{
		for (auto b : buttons) 
		{
			b->Register();
		}
	}
	this->buttons[current]->SetSprite(true);
}

void ButtonManager::Periodic()
{
	if (InputManager::GetKeyDown(VK_RIGHT) || InputManager::GetKeyDown(VK_DOWN))
	{
		ChangeButton(1);
	}
	else if (InputManager::GetKeyDown(VK_LEFT) || InputManager::GetKeyDown(VK_UP))
	{
		ChangeButton(-1);
	}

	if (InputManager::GetKeyDown(VK_Z)) {
		InputManager::UseInput(VK_Z);
		buttons[current]->Clicked();
	}
}

void ButtonManager::Exit()
{
	for (auto b : buttons) 
	{
		b->SetSprite(false);
		if (!alwaysShowing) 
		{
			b->UnRegister();
		}
	}
}

void ButtonManager::ChangeButton(int amount)
{
	buttons[current]->SetSprite(false);

	current += amount;
	current = ((current % buttons.size()) + buttons.size()) % buttons.size();

	buttons[current]->SetSprite(true);
}
