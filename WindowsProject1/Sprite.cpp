#include "Sprite.h"

Sprite::Sprite() : bitmap(NULL) {
	position = Vector2::Zero();
	rotation = 0;
	scale = Vector2::One();
}

void Sprite::Draw() {
	Drawer::RegisterDraw(this);
}

ID2D1Bitmap** Sprite::GetBitmap() {
	return &bitmap;
}
