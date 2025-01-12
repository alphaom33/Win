#include "Fly.h"
#include "Battle.h"
#include "ColliderController.h"
#include "GameManager.h"
#include "Time.h"

Fly::Fly() : Fly(Vector2(), Vector2(20, 20)) {}

Fly::Fly(Vector2 pos, Vector2 scale) : TimedCode(State::BULLET)
{
	this->pos = pos;
	this->scale = scale;

	sprite = new AnimatedSprite(pos, scale, { L"fly.bmp", L"fly2.bmp"}, 1.5, 0, false);

	ColliderController::RegisterCollider(this);
}

void Fly::SetPos(Vector2 pos)
{
	this->pos = pos;
}

double Fly::GetDamage()
{
	return 5;
}

void Fly::Hide(bool hide)
{
	if (hide) 
	{
		sprite->Hide();
	}
	else 
	{
		sprite->Show();
	}
}

Vector2 Fly::GetSize()
{
	return scale;
}

Vector2 Fly::GetPosition()
{
	return pos;
}

std::wstring Fly::GetName()
{
	return L"Bullet";
}

void Fly::OnCollision(ICollider* other)
{
}

void Fly::Enter()
{
}

void Fly::Periodic()
{
	pos = pos + (Battle::GetPlayer()->GetPos() - pos).Normalized() * speed * Time::deltaTime;
	sprite->SetPosition(pos);
}

void Fly::Exit()
{
	sprite->Hide();
	GameManager::QueueUnRegisterTimedCode(this);
}

void Fly::OnUnregister()
{
	ColliderController::UnRegisterCollider(this);
	delete this;
}
