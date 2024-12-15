#include "FightMenu.h"
#include "GameManager.h"
#include "InputManager.h"

FightMenu::FightMenu(Vector2* pos, Vector2* scale) : Menu(L"")
{
	pointer = new Sprite(GetPos(), new Vector2(30, 150), NULL);
	pointer->Hide();

	background = new Sprite(new Vector2(pos->x, pos->y), new Vector2(scale->x, scale->y), NULL);
	background->Hide();
}

void FightMenu::Enter()
{
	pointer->SetPosition(GetPos());

	background->Show();
	pointer->Show();
}

void FightMenu::Periodic()
{
	pointer->SetPosition(*pointer->GetPosition() + Vector2(speed, 0));
	if (pointer->GetPosition()->x >= 825)
	{
		GameManager::SetState(State::ENEMY);
	}

	if (InputManager::GetKeyDown(VK_Z) || InputManager::GetKeyDown(VK_X)) {
		float halfRange = (825 - GetPos()->x) / 2;
		float dst = halfRange + GetPos()->x - pointer->GetPosition()->x;
		float damage = 1 - (abs(dst) / halfRange);
		OutputDebugString(std::to_wstring(damage).c_str());
		GameManager::SetState(State::ENEMY);
	}
}

void FightMenu::Exit()
{
	background->Hide();
	pointer->Hide();
}
