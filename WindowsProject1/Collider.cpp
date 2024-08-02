#include "Collider.h"
#include "ColliderController.h"

Collider::Collider(Vector2* position, Vector2* size) : ICollider()
{
	this->size = size;
	this->position = position;
	this->collided = false;
	ColliderController::RegisterCollider(this);
}

Collider::Collider(Vector2* position, Vector2* size, std::wstring name)
{
	this->position = position;
	this->size = size;
	this->name = name;
	this->collided = false;
	ColliderController::RegisterCollider(this);
}

Vector2* Collider::GetSize()
{
	return size;
}

Vector2* Collider::GetPosition()
{
	return position;
}

bool Collider::GetCollided()
{
	return collided;
}

std::wstring Collider::GetName()
{
	return name;
}

void Collider::SetSize(Vector2* newSize)
{
	size = newSize;
}

void Collider::SetPosition(Vector2* newPos)
{
	position = newPos;
}

void Collider::SetCollided(bool collided)
{
	this->collided = collided;
}
