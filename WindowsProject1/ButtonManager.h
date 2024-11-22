#include "vector"
#include "Button.h"
#include "TimedCode.h"

#pragma once
class ButtonManager : TimedCode
{
public:
	ButtonManager(std::vector<Button*> buttons);

	void Enter();
	void Periodic();
	void Exit();

	void ChangeButton(int amount);

private:
	std::vector<Button*> buttons;
	int current;
};

