#include "Main.h"
#include "PlayerController.h"
#include "Box.h"

Main::Main(HWND hwnd) : TimedCode() {
	new PlayerController(hwnd);
	//new Box(hwnd, new Vector2(200, 300));
	new Sprite(new Vector2(400, 400), new Vector2(100, 100), hwnd);
	Collider* a = new Collider(new Vector2(400, 400), new Vector2(100, 100));
	a->name = std::wstring(L"aaahhhh");
}

void Main::Start() {
}

void Main::Periodic() {
}
