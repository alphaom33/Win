#include "Vector2.h"

Vector2::Vector2() {
	x = y = 0;
}

Vector2::Vector2(double x, double y) {
	this->x = x;
	this->y = y;
}

Vector2 Vector2::Normalized() {
	return Vector2(x / Length(), y / Length());
}

Vector2 Vector2::WithX(double x)
{
	return Vector2(x, y);
}

Vector2 Vector2::Withy(double y)
{
	return Vector2(x, y);
}

float Vector2::Length() {
	return sqrt(pow(x, 2) + pow(y, 2));
}

std::wstring Vector2::ToString()
{
	return std::to_wstring(x) + L", " + std::to_wstring(y);
}

Vector2 Vector2::Zero() {
	return Vector2(0, 0);
}
Vector2 Vector2::One() {
	return Vector2(1, 1);
}

Vector2 Vector2::operator+(Vector2 rhs)
{
	return Vector2(x + rhs.x, y + rhs.y);
}

Vector2 Vector2::operator+=(Vector2 lhs)
{
	x += lhs.x;
	y += lhs.y;
	return *this;
}

Vector2 Vector2::operator-(Vector2 rhs)
{
	return Vector2(x - rhs.x, y - rhs.y);
}

Vector2 Vector2::operator*(Vector2 rhs)
{
	return Vector2(x * rhs.x, y * rhs.y);
}

Vector2 Vector2::operator*(double rhs)
{
	return Vector2(x * rhs, y * rhs);
}

bool Vector2::operator==(Vector2 rhs)
{
	return x == rhs.x && y == rhs.y;
}

Vector2 Vector2::operator/(double rhs)
{
	return Vector2(x / rhs, y / rhs);
}
