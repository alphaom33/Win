#include "SpriteCollider.h"
#include "Print.h"
#include "GameManager.h"
#include "ColliderController.h"

SpriteCollider::SpriteCollider(Vector2* position, Vector2* size, HWND hwnd, std::wstring bitmap) : SpriteCollider(position, size, hwnd, bitmap, 0, false) {}

SpriteCollider::SpriteCollider(Vector2* position, Vector2* size, HWND hwnd, std::wstring bitmap, double rotation, bool fromCorner) : TimedCode(State::BULLET)
{
	this->position = position;
	this->scale = scale;
	sprite = new Sprite(position, size, hwnd, bitmap, rotation, fromCorner);
	collider = new Collider(position, size);
}

SpriteCollider::~SpriteCollider()
{
	sprite->Hide();
	delete sprite;

	ColliderController::QueueUnRegisterCollider(collider);
	delete collider;
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
	collider->SetPos(newPos);
}

void SpriteCollider::SetScale(Vector2* newScale)
{
	this->scale = newScale;
	sprite->SetScale(newScale);
	collider->SetScale(newScale);
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

void SpriteCollider::Hide()
{
	sprite->Hide();
}

void SpriteCollider::Show()
{
	sprite->Show();
}
