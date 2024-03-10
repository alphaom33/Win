#pragma once

#include "MoreVK.h"
#include <WinUser.h>

bool keysDown[HIGH_KEY];
bool keysUp[HIGH_KEY];

void SetKeyDown(int key) {
	keysDown[key] = true;
}
void SetKeyUp(int key) {
	keysUp[key] = true;
}

bool GetKeyDown(int key) {
	return keysDown[key];
}
bool GetKeyUp(int key) {
	return keysUp[key];
}

bool GetKey(int key) {
	return GetKeyState(key) & 0x8000;
}

void ResetKeys() {
	for (int i = 0; i < sizeof(keysDown); i++) {
		keysDown[i] = false;
		keysUp[i] = false;
	}
}

