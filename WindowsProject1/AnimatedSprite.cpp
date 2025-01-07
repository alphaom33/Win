#include "AnimatedSprite.h"
#include "Print.h"
#include "Drawer.h"
#include "thread"
#include "Time.h"
AnimatedSprite::AnimatedSprite(Vector2 position, Vector2 scale, std::vector<std::wstring> frames, double speed) : AnimatedSprite(position, scale, frames, speed, 0, false) {}

AnimatedSprite::AnimatedSprite(Vector2 position, Vector2 scale, std::vector<std::wstring> frames, double speed, double rotation, bool yep) : TimedCode(State::BULLET)
{
	this->position = position;
	this->scale = scale;

	this->frames = frames;
	this->current = frames[0];
	this->speed = speed;

	this->rotation = rotation;

	startTime = 0;

	if (yep)
	{
		Drawer::RegisterDraw(this, frames);
	}
}

Vector2 AnimatedSprite::GetPosition()
{
	return position;
}

Vector2 AnimatedSprite::GetScale()
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

void AnimatedSprite::Enter()
{
}

void AnimatedSprite::Periodic()
{
	current = frames[(int)round(Time::currentTime - startTime) % frames.size()];
}

void AnimatedSprite::Exit()
{
}

void AnimatedSprite::SetPosition(Vector2 pos)
{
	position = pos;
}

void AnimatedSprite::Show()
{
	Drawer::RegisterDraw(this, {});
}

void AnimatedSprite::Hide()
{
	Drawer::UnRegisterDraw(this);
}

double AnimatedSprite::GetRotation()
{
	return rotation;
}
