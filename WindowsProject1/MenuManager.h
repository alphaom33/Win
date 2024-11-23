#include "Menu.h"
#include "TimedCode.h"

#pragma once
class MenuManager
{
public:
	static void SetMenu(Menu* menu);

private:
	static Menu* menu;
};

