#pragma once
#include "math.h"

class Vector2
{
public:
	double x;
	double y;

	Vector2();
	Vector2(double x, double y);

	Vector2* Normalized();

	float Length();

	static Vector2* Zero();
	static Vector2* One();

	Vector2* operator +(Vector2 lhs);
	bool operator ==(Vector2 rhs);
};

