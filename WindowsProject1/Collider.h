#include "Vector2.h"
#include "Windows.h"
#include "ICollider.h"
#include "string"
#pragma once
class Collider : ICollider
{
public:
	Collider(Vector2*, Vector2*);

	Vector2* GetSize();
	Vector2* GetPosition();
	void SetCollided(bool);
	std::wstring GetName();

	Vector2* position;
	Vector2* size;

	bool collided;
	std::wstring name;
};

