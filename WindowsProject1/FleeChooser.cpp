#include "FleeChooser.h"
#include "InputManager.h"
#include "MoreVK.h"
#include "GameManager.h"
#include "State.h"
#include "FleeMenu.h"

FleeChooser::FleeChooser() : Menu(new Vector2(100, 150), new Vector2(400, 400), L"", 20)
{
	MenuManager* menuManager = new MenuManager(State::FLEE);
	buttons = new ButtonManager({
		new Button(
			L"Flee",
			L"C:\\Users\\mBorchert\\Desktop\\nothing.bmp",
			L"C:\\Users\\mBorchert\\Desktop\\dsfmask.bmp",
			new Vector2(100, 150),
			new Vector2(200, 100),
			new FleeMenu(),
			menuManager,
			State::FLEE),
		new Button(
			L"Spare",
			L"C:\\Users\\mBorchert\\Desktop\\nothing.bmp",
			L"C:\\Users\\mBorchert\\Desktop\\dsfmask.bmp",
			new Vector2(100, 300),
			new Vector2(200, 100),
			NULL,
			menuManager,
			State::MENU) },
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
