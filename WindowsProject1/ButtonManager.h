#include "vector"
#include "Button.h"
#include "TimedCode.h"

#pragma once
class ButtonManager : public TimedCode
{
public:
	ButtonManager(std::vector<IButton*> buttons, bool alwaysShowing, State state);
	~ButtonManager();

	void Enter();
	void Periodic();
	void Exit();

	void ChangeButton(int amount);

private:
	std::vector<IButton*> buttons;
	int current;
	bool alwaysShowing;
};

