#include "vector"
#include "Button.h"
#include "TimedCodeMenu.h"

#pragma once
class ButtonManager : TimedCodeMenu
{
public:
	ButtonManager(std::vector<Button*> buttons);

	void MenuEnter();
	void MenuPeriodic();
	void MenuExit();

	void ChangeButton(int amount);

private:
	std::vector<Button*> buttons;
	int current;
};

