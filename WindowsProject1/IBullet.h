#include "Vector2.h"

#pragma once
class IBullet {
public:
	virtual void SetPos(Vector2 pos) = 0;
	virtual double GetDamage() = 0;
};
