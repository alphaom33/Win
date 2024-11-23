#include "Sprite.h"
#include "IDrawable.h"
#include "TimedCode.h"
#include "Menu.h"

#pragma once
class Button : IDrawable, ITextable, TimedCode
{
public:
	Button(std::wstring text, std::wstring on, std::wstring off, Vector2* pos, Vector2* scale, Menu* menu);
	void SetSprite(bool on);

	std::wstring GetBitmap();
	Vector2* GetPosition();
	Vector2* GetScale();

private:
	Vector2* position;
	Vector2* scale;

	std::wstring text;

	bool currentSprite;
	std::wstring buttonOn;
	std::wstring buttonOff;

	Menu* menu;

	// Inherited via TimedCodeMenu
	void Enter() override;
	void Periodic() override;
	void Exit() override;

	// Inherited via ITextable
	std::wstring GetText() override;
	Vector2* GetPos() override;
	float GetSize() override;
};

