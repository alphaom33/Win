#include "ICollider.h"
#include "vector"
#pragma once
class ColliderController
{
public:
	static void RegisterCollider(ICollider* toRegister);
	static void UnRegisterCollider(ICollider* toUnRegister);
	static void CheckCollisions();
private:
	static std::vector<ICollider*> colliders;
};

