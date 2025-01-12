#include "ButtonManager.h"
#include "Button.h"
#include "Menu.h"
#include "MenuManager.h"
#include "LambdaButton.h"

#pragma once
class FleeChooser : public Menu
{
public:
	FleeChooser();

	void Enter() override;
	void Periodic() override;
	void Exit() override;
private:
	LambdaButton* spare;
	ButtonManager* buttons;
};
