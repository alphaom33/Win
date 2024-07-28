#include "d2d1.h"

#pragma once
class IDrawable {
public:
	virtual ID2D1Bitmap** GetBitmap() = 0;
};
