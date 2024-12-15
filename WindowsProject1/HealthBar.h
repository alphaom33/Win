#include "Sprite.h"

#pragma once
class HealthBar
{
public:
	HealthBar(Vector2* pos, Vector2* scale);

	void SetHealth(double health);

	void Hide();
	void Show();

private:
	Sprite* back;
	Sprite* front;

	double initialScale;
};

