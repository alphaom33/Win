#include "math.h"
#include <string>

#pragma once
class Vector2
{
public:
	double x;
	double y;

	Vector2();
	Vector2(double x, double y);

	Vector2 Normalized();

	float Length();
	std::wstring ToString();

	static Vector2 Zero();
	static Vector2 One();

	Vector2 operator+(Vector2 rhs);
	Vector2 operator+=(Vector2 rhs);
	Vector2 operator-(Vector2 rhs);
	Vector2 operator*(Vector2 rhs);
	bool operator==(Vector2 rhs);

	Vector2 operator*(double rhs);
	Vector2 operator/(double rhs);
};

