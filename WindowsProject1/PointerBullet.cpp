#include "PointerBullet.h"
#include "PlayerController.h"

PointerBullet::PointerBullet() : TimedCode(State::BULLET)
{
	sprite = new Sprite(new Vector2(), new Vector2(100, 100), NULL);
}

void PointerBullet::SetPos(Vector2* pos)
{
	sprite->SetPosition(pos);
}

void PointerBullet::Enter()
{
}

Vector2 center = Vector2(250, 200);
void PointerBullet::Periodic()
{
	sprite->SetPosition(*sprite->GetPosition() + *(center - *sprite->GetPosition())->Normalized());
}

void PointerBullet::Exit()
{
}
