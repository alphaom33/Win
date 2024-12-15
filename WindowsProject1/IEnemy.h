#include "Turn.h"

#pragma once
class IEnemy {
public:
	struct Action {
		Action(IEnemy* enemy, std::wstring name, void(*lambda)(IEnemy* enemy)) {
			this->enemy = enemy;
			this->name = name;
			this->lambda = lambda;
		}

		IEnemy* enemy;
		std::wstring name;

		void(*lambda)(IEnemy* enemy);
	};

	virtual std::vector<Action> GetActions() = 0;
	virtual Turn* GetTurn() = 0;
	virtual void Damage(double damage) = 0;
};
