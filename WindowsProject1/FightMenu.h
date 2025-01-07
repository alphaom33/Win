#include "Menu.h"
#include "Sprite.h"

#pragma once
class FightMenu : public Menu
{
public:
	FightMenu(Vector2 pos, Vector2 scale);

	void Enter() override;
	void Periodic() override;
	void Exit() override;

private:
	const double speed = 1000;

	Sprite* pointer;
	Sprite* background;
};
