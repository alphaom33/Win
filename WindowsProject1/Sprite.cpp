#include "Sprite.h"

Sprite::Sprite(Vector2* position, Vector2* scale, HWND hwnd, std::wstring sprite) : Sprite(position, scale, hwnd, sprite, 0) {}

Sprite::Sprite(Vector2* position, Vector2* scale, HWND hwnd, std::wstring sprite, double rotation)
{
	this->position = position;
	this->scale = scale;
	this->rotation = rotation;
	this->hwnd = hwnd;
	this->sprite = sprite;

	Drawer::RegisterDraw(this, { sprite });
}

Sprite::~Sprite()
{
	Drawer::UnRegisterDraw(this);
}

Vector2* Sprite::GetPosition() {
	return position;
}

Vector2* Sprite::GetScale()
{
	return scale;
}

void Sprite::SetPosition(Vector2* newPos)
{
	position = newPos;
}

void Sprite::SetScale(Vector2* newScale)
{
	scale = newScale;
}

void Sprite::Hide()
{
	Drawer::UnRegisterDraw(this);
}

void Sprite::Show()
{
	Drawer::RegisterDraw(this, {});
}

double Sprite::GetRotation()
{
	return rotation;
}

std::wstring Sprite::GetBitmap() {
	return sprite;
}
