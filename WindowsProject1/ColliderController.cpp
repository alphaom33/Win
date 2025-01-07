#include "ColliderController.h"
#include "Print.h"

std::vector<ICollider*> ColliderController::colliders;
std::queue<ICollider*> ColliderController::toFree;

void ColliderController::RegisterCollider(ICollider* toRegister)
{
	colliders.push_back(toRegister);
}

void ColliderController::UnRegisterCollider(ICollider* toUnRegister)
{
	auto index = std::find(colliders.begin(), colliders.end(), toUnRegister);
	if (index != colliders.end()) {
		colliders.erase(index);
	}
}

void ColliderController::QueueUnRegisterCollider(ICollider* toUnRegister)
{
	toFree.push(toUnRegister);
}

bool ColliderController::GetCollideds(Vector2 aPos, Vector2 aScale, Vector2 bPos, Vector2 bScale)
{
	bool sideIntersecta = CheckIntersect(aPos.x, aScale.x, bPos.x, bScale.x);
	bool topIntersecta = CheckIntersect(aPos.y, aScale.y, bPos.y, bScale.y);

	bool sideIntersectb = CheckIntersect(bPos.x, bScale.x, aPos.x, aScale.x);
	bool topIntersectb = CheckIntersect(bPos.y, bScale.y, aPos.y, aScale.y);

	return (sideIntersecta || sideIntersectb) && (topIntersecta || topIntersectb);
}

bool ColliderController::GetCollideds(ICollider* a, ICollider* b)
{
	return GetCollideds(a->GetPosition(), a->GetSize(), b->GetPosition(), b->GetSize());
}

void ColliderController::CheckCollisions()
{
	for (int i = 0; i < colliders.size(); i++)
	{
		for (int j = i + 1; j < colliders.size(); j++) {

			if (GetCollideds(colliders[i], colliders[j])) {
				colliders[i]->OnCollision(colliders[j]);
				colliders[j]->OnCollision(colliders[i]);
			}
		}
	}

	while (toFree.size()) {
		UnRegisterCollider(toFree.front());
		toFree.pop();
	}
}

bool ColliderController::CheckBox(Vector2 pos, Vector2 scale, std::wstring filter) {

	for (int i = 0; i < colliders.size(); i++)
	{
		if (GetCollideds(colliders[i]->GetPosition(), colliders[i]->GetSize(), pos, scale) && colliders[i]->GetName() != filter) {
			return true;
		}
	}
	return false;
}

void ColliderController::Reset()
{
	colliders.clear();
}

bool ColliderController::CheckIntersect(double aPos, double aScale, double bPos, double bScale)
{
	double rightPos = aPos + aScale;
	bool collidedRight = rightPos > bPos &&
		rightPos < bPos + bScale;

	double leftPos = aPos;
	bool collidedLeft = leftPos > bPos &&
		leftPos < bPos + bScale;

	return collidedLeft || collidedRight;
}
