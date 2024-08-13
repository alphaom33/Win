#include "SpriteCollider.h"
#include "TimedCodeBullet.h"

#pragma once
class Box : TimedCodeBullet
{
public:
	Box(HWND, Vector2*);
	void BulletEnter();
	void BulletPeriodic();
	void BulletExit();
private:
	SpriteCollider* left;
	SpriteCollider* right;
	SpriteCollider* top;
	SpriteCollider* bottom;

	SpriteCollider* topLeft;
	SpriteCollider* topRight;
	SpriteCollider* bottomLeft;
	SpriteCollider* bottomRight;

	Vector2 pos = Vector2(500, 100);
	Vector2 size;
	const double width = 64;
};

