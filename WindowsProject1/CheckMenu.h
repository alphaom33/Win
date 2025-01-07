#include "Menu.h"
#include "TimedCode.h"

#pragma once
class CheckMenu : public Menu, TimedCode
{
public:
	CheckMenu(int atk, int def, std::wstring desc);

	// Inherited via TimedCode
	void Enter() override;
	void Periodic() override;
	void Exit() override;

	void OnUnregister() override;
};

