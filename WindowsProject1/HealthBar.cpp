#include "HealthBar.h"

HealthBar::HealthBar(Vector2* pos, Vector2* scale)
{
	back = new Sprite(pos, scale, NULL);
	front = new Sprite(pos, scale, NULL);

	initialScale = scale->x;
}

void HealthBar::SetHealth(double health)
{
	front->SetScale(new Vector2(initialScale * health, front->GetScale()->y));
}

void HealthBar::Hide()
{
	front->Hide();
	back->Hide();
}

void HealthBar::Show()
{
	back->Show();
	front->Show();
}
