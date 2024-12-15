#include "SpriteCollider.h"
#include "TimedCode.h"
#include "IBullet.h"

#pragma once
class Box : TimedCode
{
public:
	Box(HWND hwnd, Vector2* pos, Vector2* startSize, int width);
	void Enter() override;
	void Periodic() override;
	void Exit() override;

	static Vector2* GetPos();
	static Vector2* GetScale();

	static void SpawnBullet(IBullet* bullet);
	static void EdgeBullet(IBullet* bullet);

private:
	SpriteCollider* left;
	SpriteCollider* right;
	SpriteCollider* top;
	SpriteCollider* bottom;

	SpriteCollider* topLeft;
	SpriteCollider* topRight;
	SpriteCollider* bottomLeft;
	SpriteCollider* bottomRight;

	static Vector2* pos;
	static Vector2* size;
	const double width = 64;
};

