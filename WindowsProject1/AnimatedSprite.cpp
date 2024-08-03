#include "AnimatedSprite.h"
#include "Print.h"
#include "Drawer.h"
#include "thread"
#include "Time.h"

AnimatedSprite::AnimatedSprite(Vector2* position, Vector2* scale, std::wstring frames[], double speed)
{
	this->position = position;
	this->scale = scale;

	this->frames = frames;
	length = frames->size();
	this->current = frames[0];
	this->speed = speed;

	bitmap = NULL;

	
	Drawer::RegisterDraw(this);
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
	return &bitmap;
}

std::wstring AnimatedSprite::GetName()
{
	return current;
}

void AnimatedSprite::Play()
{
}

void AnimatedSprite::Start()
{
	startTime = Time::currentTime;
}

void AnimatedSprite::Periodic()
{
	Print::AddPrint(std::to_wstring(Time::currentTime - startTime) + L"\n");
	current = frames[(int)round(Time::currentTime - startTime) % length];
}
