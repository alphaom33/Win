#include "ICollider.h"
#include "vector"
#pragma once
class ColliderController
{
public:
	static void RegisterCollider(ICollider* toRegister);
	static void UnRegisterCollider(ICollider* toUnRegister);

	static void CheckCollisions();
	static bool CheckBox(Vector2* pos, Vector2* scale);
private:
	static bool CheckIntersect(double aPos, double aScale, double bPos, double bScale);

	static bool GetCollideds(Vector2* aPos, Vector2* aScale, Vector2* bPos, Vector2* bScale);
	static bool GetCollideds(ICollider* a, ICollider* b);


	static std::vector<ICollider*> colliders;
};

