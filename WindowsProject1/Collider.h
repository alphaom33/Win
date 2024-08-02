#include "Vector2.h"
#include "Windows.h"
#include "ICollider.h"
#include "string"
#pragma once
class Collider : ICollider
{
public:
	Collider(Vector2* position, Vector2* size);
	Collider(Vector2* position, Vector2* size, std::wstring name);

	Vector2* GetSize();
	Vector2* GetPosition();
	bool GetCollided();
	std::wstring GetName();

	void SetSize(Vector2* newSize);
	void SetPosition(Vector2* newPosition);
	void SetCollided(bool newCollided);

	bool collided;

private:
	Vector2* position;
	Vector2* size;
	std::wstring name;
};

