#include "TimedCode.h"
#include "Sprite.h"
#include "Button.h"
#include "Menu.h"
#include "MenuManager.h"

#pragma once
class Main : public TimedCode
{
public:
	Main(HWND);

	// Inherited via TimedCode
	void Periodic() override;
	void Enter() override;
	void Exit() override;

private:
	Button* MakeButton(const wchar_t* name, int num, Menu* menu);

	MenuManager* menuManager;
};

