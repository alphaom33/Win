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

Vector2* Sprite::GetPos() {
	return position;
}

Vector2* Sprite::GetScale()
{
	return scale;
}

ID2D1Bitmap** Sprite::GetBitmap() {
	return &bitmap;
}
