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
#include "ActMenu.h"
#include "Froggit.h"
#include "HealthBar.h"
#include "Battle.h"

int buttonHeight = 70;
int buttonWidth = 150;
int bottomButton = 10;
int sideButton = 50;

int middle = 150;
int buttonGap = (945 - middle - (sideButton * 2) - (4 * buttonWidth)) / 3;

Button* Main::MakeButton(const wchar_t* name, int num, Menu* menu) {
	//945, 453

	return new Button(
		name,
		L"C:\\Users\\mBorchert\\Desktop\\nothing.bmp",
		L"C:\\Users\\mBorchert\\Desktop\\dsfmask.bmp", 
		new Vector2(sideButton + (buttonGap + buttonWidth) * num + (num > 1 ? middle : 0), 453 - buttonHeight - bottomButton),
		new Vector2(buttonWidth, buttonHeight),
		menu,
		menuManager,
		State::MENU);
}

Main::Main(HWND hwnd) : TimedCode(State::ALWAYS)
{
	menuManager = new MenuManager(State::MENU);
	int width = 125;
	(new Menu(new Vector2(945 / 2 - width / 2 - 25, 453 - bottomButton - buttonHeight), new Vector2(50, 50), L"LV O", 15))->SetCurrent(true);
	(new Menu(new Vector2(945 / 2 - 30, 453 - bottomButton - 50), new Vector2(50, 50), L"Carha", 30))->SetCurrent(true);
	HealthBar* healthBar = new HealthBar(new Vector2(945 / 2 - width / 2, 453 - bottomButton - buttonHeight), new Vector2(width, 30));
	PlayerController* playerController = new PlayerController(healthBar, hwnd);
	Battle::SetPlayer(playerController);

	Froggit* enemy = new Froggit(hwnd);
	Battle::SetEnemy(enemy);

	Box* box = new Box(hwnd, new Vector2(sideButton * 2, 175), new Vector2(945 - (4 * sideButton), 150), 10);

	new ButtonManager({
		MakeButton(L"fight", 0, new FightMenu(box->GetPos(), box->GetScale())),
		MakeButton(L"item", 1, new ItemChooser(playerController)),
		MakeButton(L"act", 2, new ActMenu()),
		MakeButton(L"flee", 3, new FleeChooser()) },
		true,
		State::BUTTON);
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
