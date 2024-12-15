#include "Collider.h"
#include "ColliderController.h"

Collider::Collider(Vector2* position, Vector2* size) : Collider(position, size, L"") {}

Collider::Collider(Vector2* position, Vector2* size, std::wstring name)
{
	this->size = size;
	this->position = position;
	this->name = name;
	this->collided = false;

	ColliderController::RegisterCollider(this);
}

void Collider::SetCollided(bool collided)
{
	this->collided = collided;
}

bool Collider::GetCollided()
{
	return collided;
}

void Collider::SetPos(Vector2* pos)
{
	this->position = pos;
}

void Collider::SetScale(Vector2* scale)
{
	this->size = scale;
}

Vector2* Collider::GetSize()
{
	return size;
}

Vector2* Collider::GetPosition()
{
	return position;
}

std::wstring Collider::GetName()
{
	return name;
}

void Collider::OnCollision(ICollider* other)
{
	collided = true;
}
