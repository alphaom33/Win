#include "Sprite.h"

Sprite::Sprite(Vector2* position, Vector2* scale, HWND hwnd)
{
	this->position = position;
	this->scale = scale;
	this->rotation = 0;
	this->hwnd = hwnd;

	Drawer::RegisterDraw(this, { L"C:\\Users\\mBorchert\\Desktop\\dsf.bmp" });
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

std::wstring Sprite::GetBitmap() {
	return L"C:\\Users\\mBorchert\\Desktop\\dsf.bmp";
}
