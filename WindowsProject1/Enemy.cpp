#include "Enemy.h"
#include "Windows.h"
#include "Drawer.h"
#include "GameManager.h"
#include "Box.h"
#include "PointerBullet.h"
#include "PlayerController.h"
#include "Battle.h"
#include "MoreWM.h"

Enemy::Enemy(HWND hwnd) : TimedCode(State::ENEMY)
{
	this->pos = new Vector2(350, 0);
	this->scale = new Vector2(200, 175);

	this->sprite = new Sprite(pos, scale, NULL);
	this->textBox = new Sprite(*pos + Vector2(200, 0), new Vector2(100, 75), NULL);

	health = 1;
	healthBar = new HealthBar(*pos + Vector2(scale->x / 2 - 50, 10), new Vector2(100, 30));
	healthBar->Hide();

	textBox->Hide();
	actions = {
		IEnemy::Action(this, L"name", [](IEnemy* me) {

		})
	};

	texts = { L"adsf", L"csdf", L"zsdf" };
	currentText = 0;

	turns = {
		new Turn{[](){
			Box::SpawnBullet(new PointerBullet(Battle::GetPlayer()));
			Sleep(3000);
			GameManager::SetState(State::BUTTON);
		}}
	};

	this->hwnd = hwnd;
}

std::vector<IEnemy::Action> Enemy::GetActions()
{
	return actions;
}

Turn* Enemy::GetTurn()
{
	return turns[rand() / (RAND_MAX / turns.size())];
}

void Enemy::Damage(double damage)
{
	healthBar->Show();
	health -= damage;
	healthBar->SetHealth(health);
	if (health <= 0) 
	{
		SendMessage(hwnd, WM_RESET, NULL, NULL);
	}
	else 
	{
		SendMessage(hwnd, WM_PAINT, NULL, NULL);
		Sleep(1000);
		healthBar->Hide();
	}
}

int i = 0;
void Enemy::Enter()
{
	currentText = rand() / (RAND_MAX / texts.size());
	textBox->Show();
	Drawer::RegisterText(this);
	i = 0;
}

void Enemy::Periodic()
{
	i++;
	if (i > 100) {
		GameManager::SetState(State::BULLET);
	}
}

void Enemy::Exit()
{
	textBox->Hide();
	Drawer::UnRegisterText(this);
	GameManager::RunTurn(GetTurn());
}

std::wstring Enemy::GetText()
{
	return texts[currentText];
}

Vector2* Enemy::GetPos()
{
	return textBox->GetPosition();
}

float Enemy::GetSize()
{
	return 20;
}

D2D1::ColorF Enemy::GetColor()
{
	return D2D1::ColorF(0, 0, 0);
}
