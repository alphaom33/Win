#include "Vector2.h"
#include "string"
#pragma once
class ICollider {
public:
	virtual Vector2* GetSize() = 0;
	virtual Vector2* GetPosition() = 0;
	virtual void SetCollided(bool) = 0;
	virtual std::wstring GetName() = 0;
};
