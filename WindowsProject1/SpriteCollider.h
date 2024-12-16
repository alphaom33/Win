#include "Sprite.h"
#include "Collider.h"
#include "TimedCode.h"
#pragma once
class SpriteCollider : TimedCode
{
public:
	SpriteCollider(Vector2*, Vector2*, HWND, std::wstring bitmap, double rotation);
	SpriteCollider(Vector2*, Vector2*, HWND, std::wstring bitmap);
	~SpriteCollider();

	Vector2* GetPosition();
	Vector2* GetScale();

	void SetPosition(Vector2*);
	void SetScale(Vector2*);

	void Enter() override;
	void Periodic() override;
	void Exit()  override;

	void Hide();
	void Show();

private:
	Collider* collider;
	Sprite* sprite;

	Vector2* position;
	Vector2* scale;
};

