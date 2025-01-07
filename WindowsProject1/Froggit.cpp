#include "Froggit.h"
#include "Windows.h"
#include "Drawer.h"
#include "GameManager.h"
#include "Box.h"
#include "Fly.h"
#include "PlayerController.h"
#include "Battle.h"
#include "MoreWM.h"
#include "InputManager.h"
#include "CheckMenu.h"
#include "Frog.h"

Froggit::Froggit(HWND hwnd) : TimedCode(State::ENEMY)
{
	this->pos = Vector2(350, 0);
	this->scale = Vector2(200, 175);

	this->sprite = new Sprite(pos, scale, NULL, L"C:\\Users\\mBorchert\\Desktop\\frog.bmp");
	this->textBox = new Sprite(pos + Vector2(200, 0), Vector2(100, 75), NULL, L"C:\\Users\\mBorchert\\Desktop\\textbox.bmp");

	health = 1;
	healthBar = new HealthBar(pos + Vector2(scale.x / 2 - 50, 10), Vector2(100, 30));
	healthBar->Hide();

	textBox->Hide();
	actions = {
		IEnemy::Action(this, L"Check", [](IEnemy*) {
			GameManager::SetState(State::CHECK);
			(new CheckMenu(1, 1, L"Life VERY hard for this enemy"))->SetCurrent(true);
		}),
		IEnemy::Action(this, L"Scare", [](IEnemy* me) {
			((Froggit*)me)->spared = true;
			GameManager::SetState(State::ENEMY);
		}),
		IEnemy::Action(this, L"Compliment", [](IEnemy* me) {
			((Froggit*)me)->spared = true;
			GameManager::SetState(State::ENEMY);
		})
	};

	texts = { L"Ribbit" };
	currentText = 0;

	turns = {
		new Turn{[](){
			for (int i = 0; i < 7; i++) {
				auto fly = new Fly();
				Box::EdgeBullet(fly);
				Sleep(300);
				fly->Hide(false);
			}
			Sleep(6000);
			GameManager::SetState(State::BUTTON);
		}},
		new Turn([] {
			Frog* frog;
			if (rand() / (RAND_MAX / 2)) {
				frog = new Frog(Box::GetPos() + Box::GetScale(), -1);
			}
			else 
			{
				frog = new Frog(Box::GetPos() + Box::GetScale().WithX(0), 1);
			}
			while (!frog->GetEnd());
			GameManager::SetState(State::BUTTON);
		})
	};

	this->hwnd = hwnd;
	spared = false;
}

Froggit::~Froggit()
{
	Drawer::UnRegisterDraw(sprite);
	Drawer::UnRegisterDraw(textBox);
}

std::vector<IEnemy::Action> Froggit::GetActions()
{
	return actions;
}

double Froggit::GetSpare()
{
	return spared;
}

Turn* Froggit::GetTurn()
{
	return turns[rand() / (RAND_MAX / turns.size())];
}

void Froggit::Damage(double damage)
{
	healthBar->Show();
	health -= damage;
	healthBar->SetHealth(health);
	if (health <= 0) 
	{
		GameManager::Reset();
	}
	else 
	{
		SendMessage(hwnd, WM_PAINT, NULL, NULL);
		Sleep(1000);
		healthBar->Hide();
	}
}

LONGLONG getMillis() {
	FILETIME t;
	GetSystemTimeAsFileTime(&t);
	return ((LONGLONG)t.dwLowDateTime + (((LONGLONG)t.dwHighDateTime) << 32LL)) / 10000LL;
}

LONGLONG i;
void Froggit::Enter()
{
	currentText = rand() / (RAND_MAX / texts.size());
	textBox->Show();
	Drawer::RegisterText(this);
	i = getMillis();
}

void Froggit::Periodic()
{
	if (getMillis() > i + 1000 || InputManager::GetKey(VK_Z)) {
		GameManager::SetState(State::BULLET);
	}
}

void Froggit::Exit()
{
	textBox->Hide();
	Drawer::UnRegisterText(this);
	GameManager::RunTurn(GetTurn());
}

std::wstring Froggit::GetText()
{
	return texts[currentText];
}

Vector2 Froggit::GetPos()
{
	return textBox->GetPosition();
}

float Froggit::GetSize()
{
	return 20;
}

D2D1::ColorF Froggit::GetColor()
{
	return D2D1::ColorF(0, 0, 0);
}
