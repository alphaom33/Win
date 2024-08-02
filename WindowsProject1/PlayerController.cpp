#include "PlayerController.h"
#include "InputManager.h"
#include "MoreWM.h"
#include "Print.h"
#include "Collider.h"
#include "ColliderController.h"

#define SPEED 10

PlayerController::PlayerController(HWND hwnd) : TimedCode()
{
	heart = new Sprite(new Vector2(), new Vector2(100, 100), hwnd);
	this->hwnd = hwnd;
}

void PlayerController::Start()
{
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
