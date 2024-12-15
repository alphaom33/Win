#include "Action.h"

Action::Action(IEnemy* enemy, std::wstring name, void(*lambda)(IEnemy* enemy))
{
	this->enemy = enemy;
	this->name = name;
	this->lambda = lambda;
}

void Action::Invoke() {
	lambda(enemy);
}
