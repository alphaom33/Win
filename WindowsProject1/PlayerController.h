#include "TimedCode.h"
#include "Sprite.h"
#include "Collider.h"

#pragma once
class PlayerController : TimedCode
{
public:
	PlayerController(HWND);
	void Start();
	void Periodic();
private:
	Sprite* heart;
	Collider* collider;
	HWND hwnd;

};

