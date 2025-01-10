#include "ITextable.h"
#include "TimedCode.h"

#pragma once
class Menu : public ITextable
{
public:
	Menu(std::wstring text);
	Menu(std::wstring text, D2D1::ColorF color);
	Menu(Vector2 pos, Vector2 scale, std::wstring text, float size);
	Menu(Vector2 pos, Vector2 scale, std::wstring text, float size, D2D1::ColorF color);

	void SetCurrent(bool current);

	virtual void Enter();
	virtual void Periodic();
	virtual void Exit();

	void setText(std::wstring text);
	void setColor(D2D1::ColorF color);


protected:
	std::wstring GetText() override;
	Vector2 GetPos() override;
	float GetSize() override;
	D2D1::ColorF GetColor() override;

private:
	D2D1::ColorF color;
	Vector2 pos;
	Vector2 scale;
	std::wstring text;
	float size;
};

