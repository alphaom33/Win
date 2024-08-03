#include "IDrawable.h"
#include "d2d1.h"
#include "string"
#include "TimedCode.h"
#pragma once
class AnimatedSprite : IDrawable, TimedCode
{
public:
	AnimatedSprite(Vector2* position, Vector2* scale, std::wstring frames[], double speed);

	Vector2* GetPosition();
	Vector2* GetScale();
	ID2D1Bitmap** GetBitmap();
	std::wstring GetName();

	void Play();

	void Start();
	void Periodic();

private:
	int length;
	std::wstring* frames;
	std::wstring current;
	double speed;

	double startTime;

	ID2D1Bitmap* bitmap;

	Vector2* position;
	Vector2* scale;
};
