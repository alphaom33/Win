#include "IBullet.h"
#include "AnimatedSprite.h"
#include "ICollider.h"
#include "TimedCode.h"

#pragma once
class Fly : public IBullet, public ICollider, TimedCode
{
public:
	Fly();
	Fly(Vector2* pos, Vector2* scale);

	// Inherited via IBullet
	void SetPos(Vector2* pos) override;
	double GetDamage() override;

	void Hide(bool hide);

private:
	AnimatedSprite* sprite;

	Vector2* pos;
	Vector2* scale;

	const double speed = 1.5;

	// Inherited via ICollider
	Vector2* GetSize() override;
	Vector2* GetPosition() override;
	std::wstring GetName() override;
	void OnCollision(ICollider* other) override;

	// Inherited via TimedCode
	void Enter() override;
	void Periodic() override;
	void Exit() override;

	void OnUnregister() override;
};

