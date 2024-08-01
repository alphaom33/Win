#include "InputManager.h"
#include "windows.h"
#include "string"

bool InputManager::keysUp[HIGH_KEY];
bool InputManager::keysDown[HIGH_KEY];

void InputManager::ResetKeys() {
	for (int i = 0; i < sizeof(keysDown); i++) {
		keysDown[i] = false;
		keysUp[i] = false;
	}
}

bool InputManager::GetKey(int key) {
	return (1 << 15) & GetAsyncKeyState(key);
}

bool InputManager::GetKeyUp(int key) {
	return keysUp[key];
}
bool InputManager::GetKeyDown(int key) {
	return keysDown[key];
}

void InputManager::SetKeyUp(int key) {
	keysUp[key] = true;
}
void InputManager::SetKeyDown(int key) {
	keysDown[key] = true;
}
