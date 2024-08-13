#include "Sprite.h"
#include "Collider.h"
#include "TimedCodeBullet.h"
#pragma once
class SpriteCollider : TimedCodeBullet
{
public:
	SpriteCollider(Vector2*, Vector2*, HWND);

	Vector2* GetPosition();
	Vector2* GetScale();

	void SetPosition(Vector2*);
	void SetScale(Vector2*);

	void BulletEnter();
	void BulletPeriodic();
	void BulletExit();

private:
	Collider* collider;
	Sprite* sprite;

	Vector2* position;
	Vector2* scale;
};

