#include "TimedCode.h"
#include "SpriteCollider.h"
#include "Item.h"
#include "HealthBar.h"

#pragma once
class PlayerController : TimedCode, ICollider
{
public:
	PlayerController(HealthBar* healthBar, HWND hwnd);

	void Enter() override;
	void Periodic() override;
	void Exit() override;

	Vector2 GetPos();

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

	// Inherited via ICollider
	Vector2 GetSize() override;
	Vector2 GetPosition() override;
	void OnCollision(ICollider* other) override;
	std::wstring GetName() override;
};

