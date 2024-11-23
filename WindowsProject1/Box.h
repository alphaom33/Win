#include "SpriteCollider.h"
#include "TimedCode.h"

#pragma once
class Box : TimedCode
{
public:
	Box(HWND hwnd, Vector2 pos, Vector2* startSize, int width);
	void Enter() override;
	void Periodic() override;
	void Exit() override;
private:
	SpriteCollider* left;
	SpriteCollider* right;
	SpriteCollider* top;
	SpriteCollider* bottom;

	SpriteCollider* topLeft;
	SpriteCollider* topRight;
	SpriteCollider* bottomLeft;
	SpriteCollider* bottomRight;

	Vector2 pos;
	Vector2 size;
	const double width = 64;
};

