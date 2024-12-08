#include "Sprite.h"
#include "IDrawable.h"
#include "TimedCode.h"
#include "Menu.h"
#include "MenuManager.h"
#include "IButton.h"

#pragma once
class Button : IDrawable, ITextable, public IButton
{
public:
	Button(std::wstring text, std::wstring on, std::wstring off, Vector2* pos, Vector2* scale, Menu* menu, MenuManager* menuManager, State state);

	std::wstring GetBitmap();
	Vector2* GetPosition();
	Vector2* GetScale();

	void SetSprite(bool on) override;
	void Register() override;
	void UnRegister() override;

	void Clicked() override;

private:
	Vector2* position;
	Vector2* scale;

	std::wstring text;

	bool currentSprite;
	std::wstring buttonOn;
	std::wstring buttonOff;

	Menu* menu;
	MenuManager* menuManager;

	State state;

	// Inherited via ITextable
	std::wstring GetText() override;
	Vector2* GetPos() override;
	float GetSize() override;
};

