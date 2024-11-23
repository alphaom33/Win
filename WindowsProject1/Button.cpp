#include "Button.h"
#include "Drawer.h"
#include "InputManager.h"
#include "MenuManager.h"

Button::Button(std::wstring text, std::wstring on, std::wstring off, Vector2* pos, Vector2* scale, Menu* menu) : TimedCode(State::MENU)
{
	this->text = text;

	buttonOn = on;
	buttonOff = off;
	currentSprite = false;

	position = pos;
	this->scale = scale;

	this->menu = menu;

	Drawer::RegisterDraw(this, { on, off });
	Drawer::RegisterText(this);
}

void Button::SetSprite(bool on)
{
	currentSprite = on;
}


std::wstring Button::GetBitmap() {
	return currentSprite ? buttonOn : buttonOff;
}

Vector2* Button::GetPosition()
{
	return position;
}

Vector2* Button::GetScale()
{
	return scale;
}

void Button::Enter()
{
}

void Button::Periodic()
{
	if (currentSprite && InputManager::GetKeyDown(VK_Z)) {
		MenuManager::SetMenu(menu);
	}
}

void Button::Exit()
{
}

std::wstring Button::GetText()
{
	return text;
}

Vector2* Button::GetPos()
{
	return position;
}

float Button::GetSize()
{
	return 30.0f;
}
