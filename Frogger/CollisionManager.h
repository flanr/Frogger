//CollisionManager.h


#pragma once

#include <vector>

class GameObject;
class Collider;
class Vector2;

class CollisionManager
{
public:
	CollisionManager();
	~CollisionManager();

	void CheckCollision();
	Collider *CreateCollider(Vector2 &position, Vector2 &extension);
	void DestroyCollider(Collider *collider);

protected:
	std::vector<Collider*> m_object;

};

