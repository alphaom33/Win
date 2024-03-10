#include "Sprite.h"
#include "Vector2.h"

Sprite::Sprite() {
	position = Vector2::Zero();
	rotation = 0;
	scale = Vector2::One();
}
