#include "IButton.h"
#include "ITextable.h"
#include "d2d1.h"

#pragma once
class LambdaButton : ITextable, public IButton
{
public:
	LambdaButton(Vector2 pos, std::wstring text, void* state, void(*lambda)(void* state));
	LambdaButton(Vector2 pos, std::wstring text, void* state, void(*lambda)(void* state), D2D1::ColorF color);

	void SetColor(D2D1::ColorF color);

	// Inherited via IButton
	void SetSprite(bool on) override;
	void Register() override;
	void UnRegister() override;


	void Clicked() override;

private:
	Vector2 pos;
	std::wstring baseText;
	std::wstring text;

	void* state;
	void (*lambda)(void* state);

	D2D1::ColorF color;

	// Inherited via ITextable
	std::wstring GetText() override;
	Vector2 GetPos() override;
	float GetSize() override;
	D2D1::ColorF GetColor() override;
};

