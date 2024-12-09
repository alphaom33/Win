#include "Menu.h"
#include "Sprite.h"

#pragma once
class FightMenu : public Menu
{
public:
	FightMenu();

	void Enter() override;
	void Periodic() override;
	void Exit() override;

private:
	const double speed = 10;

	Sprite* pointer;
	Sprite* background;
};
