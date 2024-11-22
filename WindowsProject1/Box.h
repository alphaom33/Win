#include "SpriteCollider.h"
#include "TimedCode.h"

#pragma once
class Box : TimedCode
{
public:
	Box(HWND, Vector2*);
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

	Vector2 pos = Vector2(500, 100);
	Vector2 size;
	const double width = 64;
};

