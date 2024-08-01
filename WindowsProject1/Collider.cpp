#include "Collider.h"
#include "ColliderController.h"

Collider::Collider(Vector2* position, Vector2* size) : ICollider()
{
	this->size = size;
	this->position = position;
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

void Collider::SetCollided(bool collided)
{
	this->collided = collided;
}

std::wstring Collider::GetName()
{
	return name;
}
