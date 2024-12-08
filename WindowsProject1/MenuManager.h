#include "Menu.h"
#include "TimedCode.h"

#pragma once
class MenuManager : TimedCode
{
public:
	MenuManager(State state);
	void SetMenu(Menu* menu);

private:
	Menu* menu;

	// Inherited via TimedCode
	void Enter() override;
	void Periodic() override;
	void Exit() override;
};

