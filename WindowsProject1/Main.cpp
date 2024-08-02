#include "Main.h"
#include "PlayerController.h"
#include "Box.h"
#include "SpriteCollider.h"

Main::Main(HWND hwnd) : TimedCode() {
	new PlayerController(hwnd);
	new Box(hwnd, new Vector2(200, 300));
}

void Main::Start() {
}

void Main::Periodic() {
}
