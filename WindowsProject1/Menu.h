#include "ITextable.h"
#include "TimedCode.h"

#pragma once
class Menu : public ITextable, TimedCode
{
public:
	Menu(Vector2* pos, Vector2* scale, std::wstring text, float size);

	void SetCurrent();
	void SetNotCurrent();

private:
	Vector2* pos;
	Vector2* scale;
	std::wstring text;
	float size;

	// Inherited via ITextable
	std::wstring GetText() override;
	Vector2* GetPos() override;
	float GetSize() override;

	// Inherited via TimedCode
	void Enter() override;
	void Periodic() override;
	void Exit() override;
};

