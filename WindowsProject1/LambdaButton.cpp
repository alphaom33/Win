#include "LambdaButton.h"
#include "Vector2.h"
#include <string>
#include "Drawer.h"

LambdaButton::LambdaButton(Vector2 pos, std::wstring text, void* state, void(*lambda)(void* state)) : LambdaButton(pos, text, state, lambda, D2D1::ColorF(1, 1, 1))
{
}

LambdaButton::LambdaButton(Vector2 pos, std::wstring text, void* state, void(*lambda)(void* state), D2D1::ColorF color) : color(color)
{
	this->pos = pos;
	this->baseText = text;
	this->text = text;

	this->state = state;
	this->lambda = lambda;
	this->color = color;
}

void LambdaButton::SetColor(D2D1::ColorF color)
{
	this->color = color;
}

void LambdaButton::Clicked()
{
	lambda(state);
}

std::wstring LambdaButton::GetText()
{
	return text;
}

Vector2 LambdaButton::GetPos()
{
	return pos;
}

float LambdaButton::GetSize()
{
	return 20;
}

D2D1::ColorF LambdaButton::GetColor()
{
	return color;
}

void LambdaButton::SetSprite(bool on)
{
	if (on) 
	{
		text = L"> " + baseText;
	}
	else 
	{
		text = baseText;
	}
}

void LambdaButton::Register()
{
	Drawer::RegisterText(this);
}

void LambdaButton::UnRegister()
{
	Drawer::UnRegisterText(this);
}
