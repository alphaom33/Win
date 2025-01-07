#include "Battle.h"

PlayerController* Battle::playerController;
IEnemy* Battle::enemy;

void Battle::SetPlayer(PlayerController* p_playerController)
{
	playerController = p_playerController;
}

PlayerController* Battle::GetPlayer()
{
	return playerController;
}

void Battle::SetEnemy(IEnemy* p_enemy)
{
	enemy = p_enemy;
}

IEnemy* Battle::GetEnemy()
{
	return enemy;
}
