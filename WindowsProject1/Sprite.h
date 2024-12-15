#include "Vector2.h"
#include "Drawer.h"
#pragma once

class Sprite : IDrawable
{
public:
	Sprite(Vector2* pos, Vector2* scale, HWND hwnd);
	~Sprite();

	std::wstring GetBitmap();
	Vector2* GetPosition();
	Vector2* GetScale();

	void SetPosition(Vector2*);
	void SetScale(Vector2*);

	void Hide();
	void Show();
private:
	Vector2* position;
	int rotation;
	Vector2* scale;

	std::wstring bitmap;

	HWND hwnd;
};

