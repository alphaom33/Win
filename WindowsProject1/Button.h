#include "Sprite.h"
#include "IDrawable.h"
#include "TimedCodeMenu.h"
#include "Menu.h"

#pragma once
class Button : IDrawable, TimedCodeMenu
{
public:
	Button(std::wstring on, std::wstring off, Vector2* pos, Vector2* scale, Menu* menu);
	void SetSprite(bool on);

	std::wstring GetBitmap();
	Vector2* GetPosition();
	Vector2* GetScale();

private:
	Vector2* position;
	Vector2* scale;

	bool currentSprite;
	std::wstring buttonOn;
	std::wstring buttonOff;

	Menu* menu;

	// Inherited via TimedCodeMenu
	void MenuEnter() override;
	void MenuPeriodic() override;
	void MenuExit() override;
};

