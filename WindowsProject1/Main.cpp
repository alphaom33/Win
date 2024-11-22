#include "Main.h"
#include "Print.h"
#include "PlayerController.h"
#include "Box.h"
#include "SpriteCollider.h"
#include "AnimatedSprite.h"
#include "GameManager.h"
#include "Button.h"
#include "ButtonManager.h"
#include "vector"
#include "InputManager.h"
#include "MoreVK.h"
#include "MenuManager.h"
#include "State.h"

Main::Main(HWND hwnd) : TimedCode(State::ALWAYS)
{
	Button* a = new Button(L"C:\\Users\\mBorchert\\Desktop\\nothing.bmp",
		L"C:\\Users\\mBorchert\\Desktop\\dsfmask.bmp", 
		new Vector2(0, 0),
		new Vector2(100, 100),
		new Menu(new Vector2(0, 0), new Vector2(400, 400), L"C:\\Users\\mBorchert\\Desktop\\dsfmask.bmp", 20));
	Button* b = new Button(L"C:\\Users\\mBorchert\\Desktop\\nothing.bmp",
		L"C:\\Users\\mBorchert\\Desktop\\dsfmask.bmp", 
		new Vector2(200, 0),
		new Vector2(100, 100),
		new Menu(new Vector2(0, 0), new Vector2(400, 400), L"C:\\Users\\mBorchert\\Desktop\\nothing.bmp", 20));
	new ButtonManager({a, b});

	new PlayerController(hwnd);
	new Box(hwnd, new Vector2(200, 300));
	new AnimatedSprite(new Vector2(0, 0), new Vector2(100, 100), { L"C:\\Users\\mBorchert\\Desktop\\nothing.bmp", L"C:\\Users\\mBorchert\\Desktop\\dsfmask.bmp" }, 4);
}

void Main::Enter()
{
}

void Main::Exit()
{
}

int time = 0;
void Main::Periodic()
{
	time++;
	if (time > 300) {
		GameManager::SetState(State::BULLET);
	}
}
