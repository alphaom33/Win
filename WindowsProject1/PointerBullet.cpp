#include "PointerBullet.h"
#include "PlayerController.h"
#include "GameManager.h"
#include "ColliderController.h"
#include "Battle.h"

PointerBullet::PointerBullet(PlayerController* playerController) : TimedCode(State::BULLET)
{
	sprite = new Sprite(new Vector2(), new Vector2(100, 100), NULL);
	this->playerController = playerController;
	ColliderController::RegisterCollider(this);
}

PointerBullet::~PointerBullet()
{
	delete sprite;
}

void PointerBullet::SetPos(Vector2* pos)
{
	sprite->SetPosition(pos);
}

void PointerBullet::Enter()
{
}

void PointerBullet::Periodic()
{
	sprite->SetPosition(*sprite->GetPosition() + *(*Battle::GetPlayer()->GetPos() - *sprite->GetPosition())->Normalized());
}

void PointerBullet::Exit()
{
	ColliderController::UnRegisterCollider(this);
	GameManager::QueueUnRegisterTimedCode(this);
}

void PointerBullet::OnUnregister()
{
	delete this;
}

void PointerBullet::OnCollision(ICollider* collider)
{
	playerController->Damage(0.3);
}

Vector2* PointerBullet::GetSize()
{
	return sprite->GetScale();
}

Vector2* PointerBullet::GetPosition()
{
	return sprite->GetPosition();
}
