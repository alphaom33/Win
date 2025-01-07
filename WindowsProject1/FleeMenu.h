#include "Menu.h"
#include "MenuManager.h"

#pragma once
class FleeMenu : public Menu
{
public:
	FleeMenu();

	void Periodic() override;
};
