#include "PlayerController.h"
#include "InputManager.h"
#include "MoreWM.h"
#include "Print.h"
#include "Collider.h"
#include "ColliderController.h"
#include "algorithm"
#include "IBullet.h"
#include "Fly.h"
#include "Time.h"

#define SPEED 500

PlayerController::PlayerController(HealthBar* healthBar, HWND hwnd) : TimedCode(State::BULLET)
{
	heart = new Sprite(Vector2(200, 200), Vector2(20, 20), NULL, L"Heart.bmp");
	heart->Hide();

	items = { Item{L"snowBall", 45}, Item{L"apple", 10}};

	this->healthBar = healthBar;
	health = maxHealth;
	this->hwnd = hwnd;

	maxIFrames = 30;
	iFrames = 0;

	ColliderController::RegisterCollider(this);
}

void PlayerController::Enter()
{
	heart->Show();
	iFrames = 0;
}

void PlayerController::Periodic()
{
	iFrames--;

	Vector2 pos = heart->GetPosition();
	Vector2 newPos = Vector2();
	if (InputManager::GetKey(VK_RIGHT)) {
		newPos.x = SPEED * Time::deltaTime;
	} else if (InputManager::GetKey(VK_LEFT)) {
		newPos.x = -SPEED * Time::deltaTime;
	}

	if (!ColliderController::CheckBox(heart->GetPosition() + newPos, heart->GetScale(), L"Bullet")) {
		heart->SetPosition(heart->GetPosition() + newPos);
	}

	newPos = Vector2();
	pos = heart->GetPosition();
	if (InputManager::GetKey(VK_UP)) {
		newPos.y = -SPEED * Time::deltaTime;
	} else if (InputManager::GetKey(VK_DOWN)) {
		newPos.y = SPEED * Time::deltaTime;
	}

	if (!ColliderController::CheckBox(heart->GetPosition() + newPos, heart->GetScale(), L"Bullet")) {
		heart->SetPosition(heart->GetPosition() + newPos);
	}
}

void PlayerController::Exit()
{
	heart->Hide();
}

Vector2 PlayerController::GetPos()
{
	return heart->GetPosition();
}

std::vector<Item> PlayerController::GetItems()
{
	return items;
}

void PlayerController::UseItem(Item item)
{
	auto index = std::find_if(items.begin(), items.end(), [item](Item x) {
		OutputDebugString((x.name + L", " + item.name + L"\n").c_str());
		return x.name == item.name;
		});
	if (index == items.end()) {
		OutputDebugString(L"no item gone :(");
		return;
	}
	OutputDebugString(((*index).name + std::to_wstring((*index).healthPoints)).c_str());
	health += (*index).healthPoints;
	health = min(health, maxHealth);
	healthBar->SetHealth(health / maxHealth);
	items.erase(index);
}

void PlayerController::Damage(double damage)
{
	if (iFrames > 0) return;

	health -= damage;
	healthBar->SetHealth(health / maxHealth);
	iFrames = maxIFrames;
	if (health <= 0) {
		SendMessage(hwnd, WM_DIE, NULL, NULL);
	}
}

Vector2 PlayerController::GetSize()
{
	return heart->GetScale();
}

Vector2 PlayerController::GetPosition()
{
	return heart->GetPosition();
}

void PlayerController::OnCollision(ICollider* other)
{
	if (other->GetName() == L"Bullet") {
		Damage(dynamic_cast<IBullet*>(other)->GetDamage());
	}
}

std::wstring PlayerController::GetName()
{
	return L"Player";
}
