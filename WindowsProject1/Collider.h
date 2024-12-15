#include "Vector2.h"
#include "Windows.h"
#include "ICollider.h"
#include "string"
#pragma once
class Collider : public ICollider
{
public:
	Collider(Vector2* position, Vector2* size);

	void SetCollided(bool collided);
	bool GetCollided();

	void SetPos(Vector2* pos);
	void SetScale(Vector2* scale);

private:
	Vector2* position;
	Vector2* size;

	bool collided;

	// Inherited via ICollider
	void OnCollision(ICollider* other) override;
	Vector2* GetSize() override;
	Vector2* GetPosition() override;
};

