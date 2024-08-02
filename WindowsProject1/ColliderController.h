#include "ICollider.h"
#include "vector"
#pragma once
class ColliderController
{
public:
	static void RegisterCollider(ICollider* toRegister);
	static void UnRegisterCollider(ICollider* toUnRegister);

	static void CheckCollisions();

	static bool GetCollideds(ICollider* a, Vector2* bPos, Vector2* bScale);
	static bool GetCollideds(ICollider* a, ICollider* b);

	static bool CheckBox(Vector2* pos, Vector2* scale);
private:
	static std::vector<ICollider*> colliders;
};

