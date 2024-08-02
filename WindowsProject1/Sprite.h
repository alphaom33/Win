#include "Vector2.h"
#include "Drawer.h"
#pragma once

class Sprite : IDrawable
{
public:
	Sprite(HWND);
	Sprite(Vector2*, Vector2*, HWND);

	ID2D1Bitmap** GetBitmap();
	Vector2* GetPosition();
	Vector2* GetScale();

	void SetPosition(Vector2*);
	void SetScale(Vector2*);
private:
	Vector2* position;
	int rotation;
	Vector2* scale;

	ID2D1Bitmap* bitmap;

	HWND hwnd;
};

