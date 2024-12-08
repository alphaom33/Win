#include "TimedCode.h"
#include "Sprite.h"
#include "Item.h"

#pragma once
class PlayerController : TimedCode
{
public:
	PlayerController(HWND);
	void Enter() override;
	void Periodic() override;
	void Exit() override;

	std::vector<Item> GetItems();
	void UseItem(Item item);
private:
	Sprite* heart;
	HWND hwnd;

	std::vector<Item> items;
};

