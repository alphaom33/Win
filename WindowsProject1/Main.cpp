#include "Main.h"
#include "PlayerController.h"
#include "Box.h"
#include "SpriteCollider.h"
#include "AnimatedSprite.h"

Main::Main(HWND hwnd) : TimedCode() {
	new PlayerController(hwnd);
	new Box(hwnd, new Vector2(200, 300));
	new AnimatedSprite(new Vector2(0, 0), new Vector2(100, 100), { L"C:\\Users\\mBorchert\\Desktop\\nothing.bmp", L"C:\\Users\\mBorchert\\Desktop\\dsfmask.bmp" }, 4);
}

void Main::Start() {
}

void Main::Periodic() {
}
