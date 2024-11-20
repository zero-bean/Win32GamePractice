#include "pch.h"
#include "CollisionManager.h"
#include "Collider.h"
#include "Actor.h"

void CollisionManager::Init()
{

}

void CollisionManager::Update()
{
	vector<Collider*>& colliders = _collider;

	for (int32 i = 0; i < colliders.size(); i++) {
		for (int32 j = i + 1; j < colliders.size(); j++) {
			Collider* src = colliders[i];
			Collider* dest = colliders[j];

			if (src->CheckCollision(dest)) {
				if (src->_collisionMap.contains(dest) == false) {
					src->GetOwner()->OnComponentBeginOverlap(src, dest);
					dest->GetOwner()->OnComponentBeginOverlap(dest, src);
					src->_collisionMap.insert(dest);
					dest->_collisionMap.insert(src);
				}
			}
			else {
				if (src->_collisionMap.contains(dest)) {
					src->GetOwner()->OnComponentEndOverlap(src, dest);
					dest->GetOwner()->OnComponentEndOverlap(dest, src);
					src->_collisionMap.erase(dest);
					dest->_collisionMap.erase(src);
				}
			}
		}
	}
}

void CollisionManager::AddCollider(Collider* collider)
{
	_collider.push_back(collider);
}

void CollisionManager::RemoveCollider(Collider* collider)
{
	if (collider == nullptr)
		return;

	auto it = remove(_collider.begin(), _collider.end(), collider);
	_collider.erase(it, _collider.end());
}
