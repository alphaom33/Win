#include "Vector2.h"
#include "Drawer.h"
#pragma once

class Sprite : IDrawable
{
public:
	Sprite();
	void Draw();
	ID2D1Bitmap** GetBitmap();

	Vector2* position;
	int rotation;
	Vector2* scale;

	ID2D1Bitmap* bitmap;
};

