#include "Vector2.h"
#include "Drawer.h"
#pragma once

class Sprite : public IDrawable
{
public:
	Sprite(Vector2 pos, Vector2 scale, HWND hwnd, std::wstring sprite);
	Sprite(Vector2 pos, Vector2 scale, HWND hwnd, std::wstring sprite, double rotation, bool fromCorner);
	~Sprite();

	std::wstring GetBitmap();
	Vector2 GetPosition();
	Vector2 GetScale();

	void SetPosition(Vector2);
	void SetScale(Vector2);

	bool FromCorner() override;

	void Hide();
	void Show();
private:
	Vector2 position;
	double rotation;
	Vector2 scale;

	std::wstring sprite;

	HWND hwnd;

	bool fromCorner;

	// Inherited via IDrawable
	double GetRotation() override;
};

