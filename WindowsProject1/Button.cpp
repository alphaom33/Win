#include "Button.h"
#include "Drawer.h"
#include "InputManager.h"
#include "MenuManager.h"
#include "GameManager.h"

Button::Button(std::wstring text, std::wstring on, std::wstring off, Vector2 pos, Vector2 scale, Menu* menu, MenuManager* menuManager, State state) : color(1, 1, 1)
{
	this->text = text;

	buttonOn = on;
	buttonOff = off;
	currentSprite = false;

	position = pos;
	this->scale = scale;

	this->menu = menu;
	this->menuManager = menuManager;

	this->state = state;
}

void Button::SetSprite(bool on)
{
	currentSprite = on;
	color = on ? D2D1::ColorF(0, 0, 0) : D2D1::ColorF(1, 1, 1);
}


std::wstring Button::GetBitmap() {
	return currentSprite ? buttonOn : buttonOff;
}

Vector2 Button::GetPosition()
{
	return position;
}

Vector2 Button::GetScale()
{
	return scale;
}

void Button::Register()
{
	Drawer::RegisterDraw(this, { buttonOn, buttonOff });
	Drawer::RegisterText(this);
}

void Button::UnRegister()
{
	Drawer::UnRegisterDraw(this);
	Drawer::UnRegisterText(this);
}

void Button::Clicked()
{
	menuManager->SetMenu(menu);
	GameManager::SetState(state);
}

std::wstring Button::GetText()
{
	return text;
}

Vector2 Button::GetPos()
{
	return position;
}

float Button::GetSize()
{
	return 30.0f;
}

D2D1::ColorF Button::GetColor()
{
	return color;
}

double Button::GetRotation()
{
	return 0.0;
}
