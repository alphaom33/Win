#include "Button.h"
#include "Drawer.h"
#include "InputManager.h"
#include "MenuManager.h"

Button::Button(std::wstring on, std::wstring off, Vector2* pos, Vector2* scale, Menu* menu)
{
	buttonOn = on;
	buttonOff = off;
	currentSprite = false;

	position = pos;
	this->scale = scale;

	this->menu = menu;

	Drawer::RegisterDraw(this, { on, off });
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

void Button::MenuEnter()
{
}

void Button::MenuPeriodic()
{
	if (currentSprite && InputManager::GetKeyDown(VK_Z)) {
		MenuManager::SetMenu(menu);
	}
}

void Button::MenuExit()
{
}
