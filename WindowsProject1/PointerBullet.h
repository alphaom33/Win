#include "IBullet.h"
#include "Sprite.h"
#include "TimedCode.h"
#include "ICollider.h"
#include "PlayerController.h"

#pragma once
class PointerBullet : TimedCode, public IBullet, ICollider
{
public:
	PointerBullet(PlayerController* playerController);
	~PointerBullet();

private:
	Sprite* sprite;

	PlayerController* playerController;

	// Inherited via IBullet
	void SetPos(Vector2* pos) override;

	// Inherited via TimedCode
	void Enter() override;
	void Periodic() override;
	void Exit() override;
	void OnUnregister() override;

	void OnCollision(ICollider* collider) override;

	// Inherited via ICollider
	Vector2* GetSize() override;
	Vector2* GetPosition() override;
};

