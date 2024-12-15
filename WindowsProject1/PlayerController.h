#include "TimedCode.h"
#include "Sprite.h"
#include "Item.h"
#include "HealthBar.h"

#pragma once
class PlayerController : TimedCode
{
public:
	PlayerController(HealthBar* healthBar, HWND hwnd);

	void Enter() override;
	void Periodic() override;
	void Exit() override;

	Vector2* GetPos();

	std::vector<Item> GetItems();
	void UseItem(Item item);

	void Damage(double damage);
private:
	Sprite* heart;

	HealthBar* healthBar;
	double health;
	double maxHealth;

	double iFrames;
	double maxIFrames;
	
	std::vector<Item> items;

	HWND hwnd;
};

