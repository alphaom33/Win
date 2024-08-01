#include "Sprite.h"
#include "TimedCode.h"

#pragma once
class Box : TimedCode
{
public:
	Box(HWND, Vector2*);
	void Start();
	void Periodic();
private:
	Sprite* left;
	Sprite* right;
	Sprite* top;
	Sprite* bottom;

	Sprite* topLeft;
	Sprite* topRight;
	Sprite* bottomLeft;
	Sprite* bottomRight;

	Vector2 pos = Vector2(500, 100);
	Vector2 size;
	const double width = 64;
};

