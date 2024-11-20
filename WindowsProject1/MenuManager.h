#include "Menu.h"
#include "TimedCodeMenu.h"

#pragma once
class MenuManager : TimedCodeMenu
{
public:
	static void InitMenu();
	static void SetMenu(Menu* menu);

private:
	static Menu* menu;

	// Inherited via TimedCodeMenu
	void MenuEnter() override;
	void MenuPeriodic() override;
	void MenuExit() override;
};

