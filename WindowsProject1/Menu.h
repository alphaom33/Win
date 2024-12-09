#include "ITextable.h"
#include "TimedCode.h"

#pragma once
class Menu : public ITextable
{
public:
	Menu(std::wstring text);
	Menu(Vector2* pos, Vector2* scale, std::wstring text, float size);

	void SetCurrent(bool current);

	virtual void Enter();
	virtual void Periodic();
	virtual void Exit();

	void setText(std::wstring text);

protected:
	std::wstring GetText() override;
	Vector2* GetPos() override;
	float GetSize() override;

private:
	Vector2* pos;
	Vector2* scale;
	std::wstring text;
	float size;
};

