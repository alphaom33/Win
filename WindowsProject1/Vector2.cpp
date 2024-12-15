#include "Vector2.h"

Vector2::Vector2() {
	x = y = 0;
}

Vector2::Vector2(double x, double y) {
	this->x = x;
	this->y = y;
}

Vector2* Vector2::Normalized() {
	return new Vector2(x / Length(), y / Length());
}

float Vector2::Length() {
	return sqrt(pow(x, 2) + pow(y, 2));
}

std::wstring Vector2::ToString()
{
	return std::to_wstring(x) + L", " + std::to_wstring(y);
}

Vector2* Vector2::Zero() {
	return new Vector2(0, 0);
}
Vector2* Vector2::One() {
	return new Vector2(1, 1);
}

Vector2* Vector2::operator+(Vector2 rhs)
{
	return new Vector2(x + rhs.x, y + rhs.y);
}

Vector2* Vector2::operator+=(Vector2 lhs)
{
	x += lhs.x;
	y += lhs.y;
	return this;
}

Vector2* Vector2::operator-(Vector2 rhs)
{
	return new Vector2(x - rhs.x, y - rhs.y);
}

Vector2* Vector2::operator*(Vector2 rhs)
{
	return new Vector2(x * rhs.x, y * rhs.y);
}

bool Vector2::operator==(Vector2 rhs)
{
	return x == rhs.x && y == rhs.y;
}
