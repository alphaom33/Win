#include "IEnemy.h"

#include <string>

#pragma once
class Action {
public:
	Action(IEnemy* enemy, std::wstring name, void(*lambda)(IEnemy* enemy));

	IEnemy* enemy;
	std::wstring name;

	void(*lambda)(IEnemy* enemy);

	void Invoke();
};
