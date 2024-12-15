#include "Menu.h"
#include "ButtonManager.h"

#pragma once
class ActMenu : public Menu
{
public:
	ActMenu();

	void Enter() override;
	void Periodic() override;
	void Exit() override;

private:
	ButtonManager* buttonManager;
};

