#include "ItemChooser.h"
#include "algorithm"
#include "LambdaButton.h"
#include "InputManager.h"
#include "GameManager.h"

ItemChooser::ItemChooser(PlayerController* player) : Menu(L"")
{
	this->player = player;
	buttonManager = NULL;
}

struct data
{
	Item i;
	PlayerController* player;
};

void ItemChooser::Enter()
{
	std::vector<Item> items = player->GetItems();
	auto itemButtons = std::vector<IButton*>();

	if (items.size() > 0) 
	{
		for (int i = 0; i < items.size(); i++) 
		{
			itemButtons.push_back(new LambdaButton(*GetPos() + Vector2(i * 100, 0), items[i].name, new data{items[i], player}, [](void* state) {
				data d = *((data*)state);
				d.player->UseItem(d.i);
				GameManager::SetState(State::ENEMY);
				}));
		}
	}
	else 
	{
		itemButtons.push_back(new LambdaButton(GetPos(), L"", NULL, [](void*) {}));
	}
	
	buttonManager = new ButtonManager(
		itemButtons, 
		false,
		State::MENU);
	buttonManager->Enter();
}

void ItemChooser::Periodic()
{
	if (InputManager::GetKeyDown(VK_X)) {
		GameManager::SetState(State::BUTTON);
	}
}

void ItemChooser::Exit()
{
	GameManager::QueueUnRegisterTimedCode(buttonManager);
}

