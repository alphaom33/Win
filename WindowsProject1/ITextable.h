#include <string>
#include "Vector2.h"

#pragma once
class ITextable {
public:
	virtual std::wstring GetText() = 0;
	virtual Vector2* GetPos() = 0;
	virtual float GetSize() = 0;
};
