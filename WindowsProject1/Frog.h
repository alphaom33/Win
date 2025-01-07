#include "Sprite.h"
#include "TimedCode.h"

#pragma once
class Frog : TimedCode
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
	const double maxUpSpeed = -4;
	const double rightSpeed = 7;
	double dir;
	const double downAccel = 0.1;

	// Inherited via TimedCode
	void Enter() override;
	void Periodic() override;
	void Exit() override;
};

