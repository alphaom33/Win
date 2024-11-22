#include "SpriteCollider.h"
#include "Print.h"

SpriteCollider::SpriteCollider(Vector2* position, Vector2* size, HWND hwnd) : TimedCode(State::BULLET)
{
	this->position = position;
	this->scale = scale;
	sprite = new Sprite(position, size, hwnd);
	collider = new Collider(position, size, std::to_wstring(position->x));
}

Vector2* SpriteCollider::GetPosition()
{
	return position;
}

Vector2* SpriteCollider::GetScale()
{
	return scale;
}

void SpriteCollider::SetPosition(Vector2* newPos)
{
	this->position = newPos;
	sprite->SetPosition(newPos);
	collider->SetPosition(newPos);
}

void SpriteCollider::SetScale(Vector2* newScale)
{
	this->scale = newScale;
	sprite->SetScale(newScale);
	collider->SetSize(newScale);
}

void SpriteCollider::Enter()
{
}

void SpriteCollider::Periodic()
{

}

void SpriteCollider::Exit()
{
}
