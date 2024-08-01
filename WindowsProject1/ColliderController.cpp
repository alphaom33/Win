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

void ColliderController::CheckCollisions()
{
	for (int i = 0; i < colliders.size(); i++)
	{
		for (int j = i + 1; j < colliders.size(); j++) {
			double rightPos = colliders[i]->GetPosition()->x + colliders[i]->GetSize()->x;
			bool collidedRight = rightPos > colliders[j]->GetPosition()->x - colliders[j]->GetSize()->x &&
				rightPos < colliders[j]->GetPosition()->x + colliders[j]->GetSize()->x;

			double leftPos = colliders[i]->GetPosition()->x - colliders[i]->GetSize()->x;
			bool collidedLeft = leftPos > colliders[j]->GetPosition()->x - colliders[j]->GetSize()->x &&
				leftPos < colliders[j]->GetPosition()->x + colliders[j]->GetSize()->x;


			double topPos = colliders[i]->GetPosition()->y - colliders[i]->GetSize()->y;
			bool collidedTop = topPos > colliders[j]->GetPosition()->y - colliders[j]->GetSize()->y &&
				topPos < colliders[j]->GetPosition()->y + colliders[j]->GetSize()->y;

			double bottomPos = colliders[i]->GetPosition()->y + colliders[i]->GetSize()->y;
			bool collidedBottom = bottomPos > colliders[j]->GetPosition()->y - colliders[j]->GetSize()->y &&
				bottomPos < colliders[j]->GetPosition()->y + colliders[j]->GetSize()->y;

			colliders[i]->SetCollided((collidedRight || collidedLeft) && (collidedTop || collidedBottom));
		}
	}
}
