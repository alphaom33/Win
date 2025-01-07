#include "Sprite.h"
#include "Collider.h"
#include "TimedCode.h"
#include "IBullet.h"

#pragma once
class Frog : TimedCode, public IBullet, public ICollider
{
public:
	Frog(Vector2 pos, double dir);
	~Frog();

	Vector2 GetPos();
	Vector2 GetScale();

	bool GetEnd();
private:
	Sprite* sprite;

	double upSpeed;
	const double maxUpSpeed = -3;
	const double rightSpeed = 3.5;
	double dir;
	const double downAccel = 0.05;

	// Inherited via TimedCode
	void Enter() override;
	void Periodic() override;
	void Exit() override;

	// Inherited via IBullet
	void SetPos(Vector2 pos) override;
	double GetDamage() override;

	// Inherited via ICollider
	Vector2 GetSize() override;
	Vector2 GetPosition() override;
	std::wstring GetName() override;
};

