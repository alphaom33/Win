#include "FleeChooser.h"
#include "InputManager.h"
#include "MoreVK.h"
#include "GameManager.h"
#include "State.h"
#include "FleeMenu.h"
#include "LambdaButton.h"

struct fleeState {
	MenuManager* menuManager;
};

FleeChooser::FleeChooser() : Menu(new Vector2(100, 150), new Vector2(400, 400), L"", 20)
{
	MenuManager* menuManager = new MenuManager(State::FLEE);
	buttons = new ButtonManager({
		new LambdaButton(new Vector2(100, 150), L"Flee", new fleeState{menuManager}, [](void* state) {
			fleeState* ack = (fleeState*)state;
			ack->menuManager->SetMenu(new FleeMenu());
			GameManager::SetState(State::FLEE);
			}),
		new LambdaButton(new Vector2(100, 200), L"Spare", NULL, [](void*) {})
		},
		false,
		State::NEVER);
}

void FleeChooser::Enter()
{
	buttons->Enter();
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
