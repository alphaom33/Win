#include "Death.h"
#include "InputManager.h"
#include "GameManager.h"

Death::Death() : TimedCode(State::DEATH)
{
	sprite = new Sprite(Vector2(0, 0), Vector2(945, 500), NULL, L"C:\\Users\\mBorchert\\Desktop\\Death.bmp");
}

void Death::Enter()
{
}

void Death::Periodic()
{
	if (InputManager::GetKeyDown(VK_Z)) GameManager::Reset();
}

void Death::Exit()
{
}
