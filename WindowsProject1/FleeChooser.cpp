#include "FleeChooser.h"
#include "InputManager.h"
#include "MoreVK.h"
#include "GameManager.h"
#include "State.h"
#include "FleeMenu.h"
#include "LambdaButton.h"
#include "Battle.h"

struct fleeState {
	MenuManager* menuManager;
};

FleeChooser::FleeChooser() : Menu(L"")
{
	MenuManager* menuManager = new MenuManager(State::FLEE);
	spare = new LambdaButton(GetPos() + Vector2(0, 50), L"Spare", NULL, [](void*) {
		if (Battle::GetEnemy()->GetSpare()) GameManager::Reset();
		else GameManager::SetState(State::ENEMY);
		});
	buttons = new ButtonManager({
		new LambdaButton(GetPos(), L"Flee", new fleeState{menuManager}, [](void* state) {
			fleeState* ack = (fleeState*)state;
			ack->menuManager->SetMenu(new FleeMenu());
			GameManager::SetState(State::FLEE);
			}),
		spare
		},
		false,
		State::NEVER);
}

void FleeChooser::Enter()
{
	buttons->Enter();
	spare->SetColor(Battle::GetEnemy()->GetSpare() ? D2D1::ColorF(1, 0.9, 0.05) : D2D1::ColorF(1, 1, 1));
}

void FleeChooser::Periodic()
{
	buttons->Periodic();
	if (InputManager::GetKeyDown(VK_X)) {
		GameManager::SetState(State::BUTTON);
	}
}

void FleeChooser::Exit()
{
	buttons->Exit();
}
