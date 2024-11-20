#include "ITextable.h"

#pragma once
class Menu : public ITextable
{
public:
	Menu(Vector2* pos, Vector2* scale, std::wstring text, float size);

private:
	Vector2* pos;
	Vector2* scale;
	std::wstring text;
	float size;

	// Inherited via ITextable
	std::wstring GetText() override;
	Vector2* GetPos() override;
	float GetWidth() override;
	float GetSize() override;
};

