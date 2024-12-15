#include "LambdaButton.h"
#include "ActMenu.h"
#include "Action.h"
#include "Enemy.h"
#include "InputManager.h"
#include "GameManager.h"

#include <vector>

ActMenu::ActMenu() : Menu(L"")
{
	buttonManager = NULL;
}

struct data {
	Action action;
};

void ActMenu::Enter()
{
	std::vector<Action> actions = Enemy::GetActions();
	auto buttons = std::vector<IButton*>();
	if (actions.size() > 0) {
		for (int i = 0; i < actions.size(); i++)
		{
			buttons.push_back(new LambdaButton(*GetPos() + Vector2(i * 100, 0), actions[i].name, new data{actions[i]}, [](void* d) {
				((data*)d)->action.Invoke();
				GameManager::SetState(State::ENEMY);
				}));
		}
	}
	else 
	{
		buttons.push_back(new LambdaButton(new Vector2(100, 150), L"", NULL, [](void*) {}));
	}

	buttonManager = new ButtonManager(buttons, false, State::MENU);
	buttonManager->Enter();
}

void ActMenu::Periodic()
{
	if (InputManager::GetKeyDown(VK_X)) {
		GameManager::SetState(State::BUTTON);
	}
}

void ActMenu::Exit()
{
	GameManager::UnRegisterTimedCode(buttonManager);
}
