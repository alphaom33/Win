#include "PlayerController.h"
#include "IEnemy.h"

#pragma once
class Battle
{
public:
	static void SetPlayer(PlayerController* playerController);
	static PlayerController* GetPlayer();

	static void SetEnemy(IEnemy* enemy);
	static IEnemy* GetEnemy();
private:
	static PlayerController* playerController;
	static IEnemy* enemy;
};

