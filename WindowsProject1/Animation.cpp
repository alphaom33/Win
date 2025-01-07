#include "Animation.h"

AnimatedSprite::AnimatedSprite(Vector2* position, Vector2* scale, ID2D1Bitmap* frames[], double speed)
{
	this->position = position;
	this->scale = scale;

	this->frames = frames;
	this->current = frames[0];

	this->speed = speed;
}

void AnimatedSprite::Play()
{

}

Vector2* AnimatedSprite::GetPosition()
{
	return position;
}

Vector2* AnimatedSprite::GetScale()
{
	return scale;
}

ID2D1Bitmap** AnimatedSprite::GetBitmap()
{
	return &current;
}
