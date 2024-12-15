#include "Action.h"
#include "Sprite.h"
#include "TimedCode.h"
#include "ITextable.h"
#include "Turn.h"

#include <functional>
#include <vector>

#pragma once
class Enemy : public IEnemy, TimedCode, ITextable
{
public:
	Enemy();

	static std::vector<Action> GetActions();
	Turn* GetTurn();
private:
	static std::vector<Action> actions;
	Sprite* sprite;
	Sprite* textBox;

	Vector2* pos;
	Vector2* scale;

	std::vector<std::wstring> texts;
	int currentText;

	std::vector<Turn*> turns;

	// Inherited via TimedCode
	void Enter() override;
	void Periodic() override;
	void Exit() override;

	// Inherited via ITextable
	std::wstring GetText() override;
	Vector2* GetPos() override;
	float GetSize() override;
	D2D1::ColorF GetColor() override;
};

