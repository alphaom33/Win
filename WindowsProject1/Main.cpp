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
#include "FleeChooser.h"
#include "ItemChooser.h"
#include "FightMenu.h"

int buttonHeight = 70;
int buttonWidth = 150;
int bottomButton = 10;
int sideButton = 100;

int buttonGap = (945 - (sideButton * 2) - (4 * buttonWidth)) / 3;
MenuManager* menuManager = new MenuManager(State::MENU);

Button* MakeButton(const wchar_t* name, int num, Menu* menu) {
	//945, 453

	return new Button(
		name,
		L"C:\\Users\\mBorchert\\Desktop\\nothing.bmp",
		L"C:\\Users\\mBorchert\\Desktop\\dsfmask.bmp", 
		new Vector2(sideButton + (buttonGap + buttonWidth) * num, 453 - buttonHeight - bottomButton),
		new Vector2(buttonWidth, buttonHeight),
		menu,
		menuManager,
		State::MENU);
}

Main::Main(HWND hwnd) : TimedCode(State::ALWAYS)
{
	PlayerController* playerController = new PlayerController(hwnd);

	new ButtonManager({
		MakeButton(L"fight", 0, new FightMenu()),
		MakeButton(L"item", 1, new ItemChooser(playerController)),
		MakeButton(L"act", 2, new Menu(new Vector2(100, 150), new Vector2(400, 400), L"c", 20)),
		MakeButton(L"flee", 3, new FleeChooser()) },
		true,
		State::BUTTON);

	new Box(hwnd, Vector2(sideButton, 125), new Vector2(945 - (2 * sideButton), 200), 10);
	//new AnimatedSprite(new Vector2(0, 0), new Vector2(100, 100), { L"C:\\Users\\mBorchert\\Desktop\\nothing.bmp", L"C:\\Users\\mBorchert\\Desktop\\dsfmask.bmp" }, 4);
}

void Main::Enter()
{
}

void Main::Exit()
{
}

void Main::Periodic()
{
}
