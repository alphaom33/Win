#include "PlayerController.h"
#include "InputManager.h"
#include "MoreWM.h"
#include "Print.h"
#include "Collider.h"
#include "ColliderController.h"

#define SPEED 10

PlayerController::PlayerController(HWND hwnd) : TimedCode(State::BULLET)
{
	heart = new Sprite(new Vector2(200, 200), new Vector2(50, 50), hwnd);
	this->hwnd = hwnd;

	items = { Item{L"health", 0}, Item{L"apple", 10}};
}

void PlayerController::Enter()
{
	heart->Show();
}

void PlayerController::Periodic()
{
	Vector2* pos = heart->GetPosition();
	Vector2* newPos = new Vector2();
	if (InputManager::GetKey(VK_RIGHT)) {
		newPos->x = SPEED;
	} else if (InputManager::GetKey(VK_LEFT)) {
		newPos->x = -SPEED;
	}
	if (!ColliderController::CheckBox(*heart->GetPosition() + *newPos, heart->GetScale())) {
		heart->SetPosition(*heart->GetPosition() + *newPos);
	}

	newPos = new Vector2();
	pos = heart->GetPosition();
	if (InputManager::GetKey(VK_UP)) {
		newPos->y = -SPEED;
	} else if (InputManager::GetKey(VK_DOWN)) {
		newPos->y = SPEED;
	}

	if (!ColliderController::CheckBox(*heart->GetPosition() + *newPos, heart->GetScale())) {
		heart->SetPosition(*heart->GetPosition() + *newPos);
	}
}

void PlayerController::Exit()
{
	heart->Hide();
}

std::vector<Item> PlayerController::GetItems()
{
	return items;
}

void PlayerController::UseItem(Item item)
{
	//TODO
}
