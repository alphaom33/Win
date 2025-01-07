#include "LambdaButton.h"
#include "ActMenu.h"
#include "IEnemy.h"
#include "InputManager.h"
#include "GameManager.h"
#include "Battle.h"

#include <vector>

ActMenu::ActMenu() : Menu(L"")
{
	buttonManager = NULL;
}

struct data {
	IEnemy::Action action;
};

void ActMenu::Enter()
{
	std::vector<IEnemy::Action> actions = Battle::GetEnemy()->GetActions();
	auto buttons = std::vector<IButton*>();
	if (actions.size() > 0) {
		for (int i = 0; i < actions.size(); i++)
		{
			buttons.push_back(new LambdaButton(GetPos() + Vector2(i * 100, 0), actions[i].name, new data{actions[i]}, [](void* d) {
				((data*)d)->action.lambda(Battle::GetEnemy());
				}));
		}
	}
	else 
	{
		buttons.push_back(new LambdaButton(Vector2(100, 150), L"", NULL, [](void*) {}));
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
