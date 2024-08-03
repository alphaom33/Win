#include "d2d1.h"
#include "Vector2.h"
#include "string"

#pragma once
class IDrawable {
public:
	virtual std::wstring GetBitmap() = 0;
	virtual Vector2* GetPosition() = 0;
	virtual Vector2* GetScale() = 0;
};
