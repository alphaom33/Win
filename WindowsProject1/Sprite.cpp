#include "Sprite.h"

Sprite::Sprite(HWND hwnd)
{
	Sprite(Vector2::Zero(), Vector2::One(), hwnd);
}

Sprite::Sprite(Vector2* position, Vector2* scale, HWND hwnd) : bitmap(NULL)
{
	this->position = position;
	this->scale = scale;
	this->rotation = 0;
	this->hwnd = hwnd;

	Drawer::RegisterDraw(this);
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

ID2D1Bitmap** Sprite::GetBitmap() {
	return &bitmap;
}
