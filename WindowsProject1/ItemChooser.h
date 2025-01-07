#include "PlayerController.h"
#include "Menu.h"
#include "Button.h"
#include "ButtonManager.h"

#pragma once
class ItemChooser : public Menu
{
public:
	ItemChooser(PlayerController* player);

	void Enter() override;
	void Periodic() override;
	void Exit() override;

private:
	PlayerController* player;
	ButtonManager* buttonManager;
};

