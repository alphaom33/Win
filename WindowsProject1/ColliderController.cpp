#include "ColliderController.h"
#include "Print.h"

std::vector<ICollider*> ColliderController::colliders;

void ColliderController::RegisterCollider(ICollider* toRegister)
{
	colliders.push_back(toRegister);
}

void ColliderController::UnRegisterCollider(ICollider* toUnRegister)
{
	throw std::exception();
}

bool ColliderController::GetCollideds(ICollider* a, Vector2* bPos, Vector2* bScale)
{
	double rightPos = a->GetPosition()->x + a->GetSize()->x;
	bool collidedRight = rightPos > bPos->x - bScale->x &&
		rightPos < bPos->x + bScale->x;

	double leftPos = a->GetPosition()->x - a->GetSize()->x;
	bool collidedLeft = leftPos > bPos->x - bScale->x &&
		leftPos < bPos->x + bScale->x;


	double topPos = a->GetPosition()->y - a->GetSize()->y;
	bool collidedTop = topPos > bPos->y - bScale->y &&
		topPos < bPos->y + bScale->y;

	double bottomPos = a->GetPosition()->y + a->GetSize()->y;
	bool collidedBottom = bottomPos > bPos->y - bScale->y &&
		bottomPos < bPos->y + bScale->y;

	return (collidedRight || collidedLeft) && (collidedTop || collidedBottom);
}

bool ColliderController::GetCollideds(ICollider* a, ICollider* b)
{
	return GetCollideds(a, b->GetPosition(), b->GetSize());
}

void ColliderController::CheckCollisions()
{
	for (ICollider* a : colliders) {
		a->SetCollided(false);
	}
	for (int i = 0; i < colliders.size(); i++)
	{
		for (int j = i + 1; j < colliders.size(); j++) {

			if (GetCollideds(colliders[i], colliders[j])) {
				colliders[i]->SetCollided(true);
			}
		}
	}
}

bool ColliderController::CheckBox(Vector2* pos, Vector2* scale) {

	for (int i = 0; i < colliders.size(); i++)
	{
		if (GetCollideds(colliders[i], pos, scale)) {
			Print::AddPrint(colliders[i]->GetName());
			return true;
		}
	}
	return false;
}
