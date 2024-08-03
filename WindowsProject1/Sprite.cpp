#include "Sprite.h"

Sprite::Sprite(Vector2* position, Vector2* scale, HWND hwnd)
{
	this->position = position;
	this->scale = scale;
	this->rotation = 0;
	this->hwnd = hwnd;

	Drawer::RegisterDraw(this, { L"C:\\Users\\mBorchert\\Desktop\\dsf.bmp" });
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

std::wstring Sprite::GetBitmap() {
	return L"C:\\Users\\mBorchert\\Desktop\\dsf.bmp";
}
