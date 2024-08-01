#include "d2d1.h"
#include "Vector2.h"

#pragma once
class IDrawable {
public:
	virtual ID2D1Bitmap** GetBitmap() = 0;
	virtual Vector2* GetPos() = 0;
	virtual Vector2* GetScale() = 0;
};
