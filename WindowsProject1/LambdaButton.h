#include "IButton.h"
#include "ITextable.h"

#pragma once
class LambdaButton : ITextable, public IButton
{
public:
	LambdaButton(Vector2* pos, std::wstring text, void* state, void(*lambda)(void* stat));

	// Inherited via IButton
	void SetSprite(bool on) override;
	void Register() override;
	void UnRegister() override;


	void Clicked() override;

private:
	Vector2* pos;
	std::wstring baseText;
	std::wstring text;

	void* state;
	void (*lambda)(void* state);

	// Inherited via ITextable
	std::wstring GetText() override;
	Vector2* GetPos() override;
	float GetSize() override;
};

