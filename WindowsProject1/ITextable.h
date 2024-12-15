#include <string>
#include "Vector2.h"
#include "d2d1.h"

#pragma once
class ITextable {
public:
	virtual std::wstring GetText() = 0;
	virtual Vector2* GetPos() = 0;
	virtual float GetSize() = 0;
	virtual D2D1::ColorF GetColor() {
		return D2D1::ColorF(1, 1, 1);
	}
};
