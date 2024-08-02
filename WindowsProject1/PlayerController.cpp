#include "PlayerController.h"
#include "InputManager.h"
#include "MoreWM.h"
#include "Print.h"
#include "Collider.h"
#include "ColliderController.h"

#define SPEED 10

Collider* why;
PlayerController::PlayerController(HWND hwnd) : TimedCode()
{
	heart = new Sprite(new Vector2(), new Vector2(100, 100), hwnd);
	this->hwnd = hwnd;
	why = new Collider(new Vector2(), new Vector2(100, 100));
}

void PlayerController::Start()
{
}

void PlayerController::Periodic()
{
	Vector2* pos = heart->GetPosition();
	if (InputManager::GetKey(VK_RIGHT)) {
		Vector2* newPos = new Vector2(pos->x + SPEED, pos->y);
		heart->SetPosition(new Vector2(pos->x + SPEED, pos->y));
	} else if (InputManager::GetKey(VK_LEFT)) {
		heart->SetPosition(new Vector2(pos->x - SPEED, pos->y));
	}

	pos = heart->GetPosition();
	if (InputManager::GetKey(VK_UP)) {
		heart->SetPosition(new Vector2(pos->x, pos->y - SPEED));
	} else if (InputManager::GetKey(VK_DOWN)) {
		heart->SetPosition(new Vector2(pos->x, pos->y + SPEED));
	}

	why->SetPosition(heart->GetPosition());
	Print::AddPrint(std::to_wstring(why->GetCollided()) + L"\n");
}
