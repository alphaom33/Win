#include "IDrawable.h"
#include "d2d1.h"
#include "string"
#include "TimedCode.h"
#include "vector"
#pragma once
class AnimatedSprite : IDrawable, public TimedCode
{
public:
	AnimatedSprite(Vector2* position, Vector2* scale, std::vector<std::wstring> frames, double speed);
	AnimatedSprite(Vector2* position, Vector2* scale, std::vector<std::wstring> frames, double speed, double rotation, bool yep);

	Vector2* GetPosition();
	Vector2* GetScale();
	std::wstring GetBitmap();

	void Play();

	void Enter() override;
	void Periodic() override;
	void Exit() override;

	void SetPosition(Vector2* pos);

	void Show();
	void Hide();

private:
	std::vector<std::wstring> frames;
	std::wstring current;
	double speed;

	double startTime;

	Vector2* position;
	Vector2* scale;

	double rotation;

	// Inherited via IDrawable
	double GetRotation() override;
};
