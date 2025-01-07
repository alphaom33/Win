#include "Frog.h"
#include "GameManager.h"
#include "Box.h"

Frog::Frog(Vector2 pos, double dir) : TimedCode(State::BULLET)
{
	Vector2 scale = Vector2(100, 100);
	sprite = new Sprite(pos - (dir > 0 ? scale.WithX(0) : scale), scale, NULL, L"C:\\Users\\mBorchert\\Desktop\\smallFrog.bmp");
	upSpeed = maxUpSpeed;
	this->dir = dir;
}

Frog::~Frog()
{
	delete sprite;
}

Vector2 Frog::GetPos()
{
	return sprite->GetPosition() + sprite->GetScale();
}

Vector2 Frog::GetScale()
{
	return sprite->GetScale();
}

bool Frog::GetEnd()
{
	return GetPos().y > Box::GetPos().y + Box::GetScale().y && upSpeed > 0;
}

void Frog::Enter()
{
}

void Frog::Periodic()
{
	upSpeed += downAccel;
	sprite->SetPosition(sprite->GetPosition() + Vector2(rightSpeed * dir, upSpeed));
}

void Frog::Exit()
{
	sprite->Hide();
	GameManager::QueueUnRegisterTimedCode(this);
}
