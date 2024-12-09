#include "FightMenu.h"
#include "GameManager.h"
#include "InputManager.h"

FightMenu::FightMenu() : Menu(L"") 
{
	pointer = new Sprite(GetPos(), new Vector2(30, 150), NULL);
	pointer->Hide();

	background = new Sprite(new Vector2(100, 125), new Vector2(750, 200), NULL);
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
		GameManager::SetState(State::BULLET);
	}

	if (InputManager::GetKeyDown(VK_Z) || InputManager::GetKeyDown(VK_X)) {
		float halfRange = (825 - GetPos()->x) / 2;
		float dst = halfRange + GetPos()->x - pointer->GetPosition()->x;
		float damage = (1 - abs(dst)) / halfRange;
		GameManager::SetState(State::BULLET);
	}
}

void FightMenu::Exit()
{
	background->Hide();
	pointer->Hide();
}
