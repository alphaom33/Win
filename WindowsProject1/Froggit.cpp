#include "Froggit.h"
#include "Windows.h"
#include "Drawer.h"
#include "GameManager.h"
#include "Box.h"
#include "Fly.h"
#include "PlayerController.h"
#include "Battle.h"
#include "MoreWM.h"

Froggit::Froggit(HWND hwnd) : TimedCode(State::ENEMY)
{
	this->pos = new Vector2(350, 0);
	this->scale = new Vector2(200, 175);

	this->sprite = new Sprite(pos, scale, NULL, L"C:\\Users\\mBorchert\\Desktop\\frog.bmp");
	this->textBox = new Sprite(*pos + Vector2(200, 0), new Vector2(100, 75), NULL, L"C:\\Users\\mBorchert\\Desktop\\textbox.bmp");

	health = 1;
	healthBar = new HealthBar(*pos + Vector2(scale->x / 2 - 50, 10), new Vector2(100, 30));
	healthBar->Hide();

	textBox->Hide();
	actions = {
		IEnemy::Action(this, L"name", [](IEnemy* me) {
			
		})
	};

	texts = { L"Ribbit" };
	currentText = 0;

	turns = {
		new Turn{[](){
			Box::SpawnBullet(new Fly());
			Sleep(3000);
			GameManager::SetState(State::BUTTON);
		}}
	};

	this->hwnd = hwnd;
}

std::vector<IEnemy::Action> Froggit::GetActions()
{
	return actions;
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
void Froggit::Enter()
{
	currentText = rand() / (RAND_MAX / texts.size());
	textBox->Show();
	Drawer::RegisterText(this);
	i = 0;
}

void Froggit::Periodic()
{
	i++;
	if (i > 100) {
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

Vector2* Froggit::GetPos()
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
