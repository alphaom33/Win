#include "Main.h"

Main::Main(HWND hwnd) : TimedCode(hwnd) {
	sprite = new Sprite();
}

void Main::Start() {
}

void Main::Periodic() {
	sprite->Draw();
}
