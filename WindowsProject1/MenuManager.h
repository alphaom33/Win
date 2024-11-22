#include "Menu.h"
#include "TimedCode.h"

#pragma once
class MenuManager : TimedCode
{
public:
	static void SetMenu(Menu* menu);

private:
	static Menu* menu;

	// Inherited via TimedCodeMenu
	void Enter() override;
	void Periodic() override;
	void Exit() override;
};

