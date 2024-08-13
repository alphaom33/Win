#include "IDrawable.h"
#include "d2d1.h"
#include "string"
#include "TimedCodeBullet.h"
#include "vector"
#pragma once
class AnimatedSprite : IDrawable, TimedCodeBullet
{
public:
	AnimatedSprite(Vector2* position, Vector2* scale, std::vector<std::wstring> frames, double speed);

	Vector2* GetPosition();
	Vector2* GetScale();
	std::wstring GetBitmap();

	void Play();

	void BulletEnter();
	void BulletPeriodic();
	void BulletExit();

private:
	std::vector<std::wstring> frames;
	std::wstring current;
	double speed;

	double startTime;

	Vector2* position;
	Vector2* scale;
};
