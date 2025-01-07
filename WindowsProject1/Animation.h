#include "IDrawable.h"
#include "d2d1.h"
#pragma once
class AnimatedSprite : IDrawable {
public:
	AnimatedSprite(Vector2* position, Vector2* scale, ID2D1Bitmap* frames[], double speed);
	void Play();

	Vector2* GetPosition();
	Vector2* GetScale();
	ID2D1Bitmap** GetBitmap();

private:
	ID2D1Bitmap** frames;
	double speed;

	ID2D1Bitmap* current;

	Vector2* position;
	Vector2* scale;
};
