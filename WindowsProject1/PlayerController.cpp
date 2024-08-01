#include "PlayerController.h"
#include "InputManager.h"
#include "MoreWM.h"
#include "Print.h"

#define SPEED 10

PlayerController::PlayerController(HWND hwnd) : TimedCode()
{
	heart = new Sprite(new Vector2(10.0f, 100.0f), new Vector2(100.0f, 100.0f), hwnd);
	collider = new Collider(new Vector2(100.0f, 100.0f), new Vector2(10.0f, 10.0f));
	collider->name = std::wstring(L"whyyyy");
	this->hwnd = hwnd;
}

void PlayerController::Start()
{
}

void PlayerController::Periodic()
{
	if (InputManager::GetKey(VK_RIGHT)) {
		heart->position->x += SPEED;
	} else if (InputManager::GetKey(VK_LEFT)) {
		heart->position->x -= SPEED;
	}
	if (InputManager::GetKey(VK_UP)) {
		heart->position->y -= SPEED;
	} else if (InputManager::GetKey(VK_DOWN)) {
		heart->position->y += SPEED;
	}
	collider->position = heart->position;
	Print::AddPrint(std::to_wstring(collider->collided) + L"\n");
}
