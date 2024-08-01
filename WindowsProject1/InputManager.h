#include "MoreVK.h"
#pragma once
class InputManager {
public:

	static void SetKeyDown(int key);
	static void SetKeyUp(int key);

	static bool GetKeyDown(int key);
	static bool GetKeyUp(int key);

	static bool GetKey(int key);

	static void ResetKeys();
private:
	static bool keysDown[HIGH_KEY];
	static bool keysUp[HIGH_KEY];
};
