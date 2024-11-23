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

int buttonHeight = 70;
int buttonWidth = 150;
int bottomButton = 10;
int sideButton = 100;

int buttonGap = (945 - (sideButton * 2) - (4 * buttonWidth)) / 3;

Button* MakeButton(const wchar_t* name, int num) {
	//945, 453

	return new Button(
		name,
		L"C:\\Users\\mBorchert\\Desktop\\nothing.bmp",
		L"C:\\Users\\mBorchert\\Desktop\\dsfmask.bmp", 
		new Vector2(sideButton + (buttonGap + buttonWidth) * num, 453 - buttonHeight - bottomButton),
		new Vector2(buttonWidth, buttonHeight),
		new Menu(new Vector2(0, 0), new Vector2(400, 400), L"C:\\Users\\mBorchert\\Desktop\\dsfmask.bmp", 20));
}

Main::Main(HWND hwnd) : TimedCode(State::ALWAYS)
{
	new ButtonManager({
		MakeButton(L"fight", 0),
		MakeButton(L"item", 1),
		MakeButton(L"act", 2),
		MakeButton(L"flee", 3) });

	new PlayerController(hwnd);
	new Box(hwnd, Vector2(sideButton, 125), new Vector2(945 - (2 * sideButton), 200), 10);
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
	if (time == 300) {
		GameManager::SetState(State::BULLET);
	}
}
