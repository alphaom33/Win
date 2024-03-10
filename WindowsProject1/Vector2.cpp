#include "Vector2.h"

Vector2::Vector2() {
	x = y = 0;
}

Vector2::Vector2(float x, float y) {
	this->x = x;
	this->y = y;
}

Vector2* Vector2::Normalized() {
	return new Vector2(x / Length(), y / Length());
}

float Vector2::Length() {
	return sqrt(pow(x, 2) + pow(y, 2));
}

Vector2* Vector2::Zero() {
	return new Vector2(0, 0);
}
Vector2* Vector2::One() {
	return new Vector2(1, 1);
}
