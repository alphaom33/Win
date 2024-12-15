#include "Sprite.h"
#include "TimedCode.h"
#include "ITextable.h"
#include "Turn.h"
#include "HealthBar.h"
#include "IEnemy.h"

#include <functional>
#include <vector>

#pragma once
class Enemy : public IEnemy, TimedCode, ITextable
{
public:
	Enemy(HWND hwnd);

	Turn* GetTurn();

	void Damage(double damage);
private:
	std::vector<IEnemy::Action> actions;
	Sprite* sprite;
	Sprite* textBox;

	double health;
	HealthBar* healthBar;

	Vector2* pos;
	Vector2* scale;

	std::vector<std::wstring> texts;
	int currentText;

	std::vector<Turn*> turns;

	HWND hwnd;

	// Inherited via TimedCode
	void Enter() override;
	void Periodic() override;
	void Exit() override;

	// Inherited via ITextable
	std::wstring GetText() override;
	Vector2* GetPos() override;
	float GetSize() override;
	D2D1::ColorF GetColor() override;

	// Inherited via IEnemy
	std::vector<IEnemy::Action> GetActions() override;
};

