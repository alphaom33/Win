#include "AnimatedSprite.h"
#include "Print.h"
#include "Drawer.h"
#include "thread"
#include "Time.h"

AnimatedSprite::AnimatedSprite(Vector2* position, Vector2* scale, std::vector<std::wstring> frames, double speed)
{
	this->position = position;
	this->scale = scale;

	this->frames = frames;
	this->current = frames[0];
	this->speed = speed;

	startTime = 0;

	Drawer::RegisterDraw(this, frames);
}

Vector2* AnimatedSprite::GetPosition()
{
	return position;
}

Vector2* AnimatedSprite::GetScale()
{
	return scale;
}

std::wstring AnimatedSprite::GetBitmap()
{
	return current;
}

void AnimatedSprite::Play()
{
}

void AnimatedSprite::BulletEnter()
{
}

void AnimatedSprite::BulletPeriodic()
{
	current = frames[(int)round(Time::currentTime - startTime) % frames.size()];
}

void AnimatedSprite::BulletExit()
{
}
