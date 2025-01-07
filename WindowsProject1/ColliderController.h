#include "ICollider.h"

#include <vector>
#include <queue>

#pragma once
class ColliderController
{
public:
	static void RegisterCollider(ICollider* toRegister);
	static void QueueUnRegisterCollider(ICollider* toUnRegister);
	static void UnRegisterCollider(ICollider* toUnRegister);

	static void CheckCollisions();
	static bool CheckBox(Vector2* pos, Vector2* scale, std::wstring filter);

	static void Reset();
private:
	static bool CheckIntersect(double aPos, double aScale, double bPos, double bScale);

	static bool GetCollideds(Vector2* aPos, Vector2* aScale, Vector2* bPos, Vector2* bScale);
	static bool GetCollideds(ICollider* a, ICollider* b);


	static std::vector<ICollider*> colliders;
	static std::queue<ICollider*> toFree;
};

