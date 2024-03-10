#include "TimedCode.h"
#include <Windows.h>
#include "RunCodePeriodicallyMaybe.h"

Stuffness::Stuffness(HWND hwnd) : TimedCode(hwnd) {
}

void Stuffness::Start() {
	//MessageBox(m_hwnd, L"kasdjf", L"weoru", MB_OK);
}

void Stuffness::Periodic() {
//	MessageBox(m_hwnd, L"es", L"no", MB_OK);
}