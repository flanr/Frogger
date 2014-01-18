//CollisionManager.h


#pragma once

#include <vector>

class GameObject;
class Collider;
class Vector2;
class GameObjectManager;

class CollisionManager
{
public:
	CollisionManager(GameObjectManager *gom);
	~CollisionManager();

	void CheckCollision();
	Collider *CreateCollider(Vector2 &position, Vector2 &extension);
	void DestroyCollider(Collider *collider);

protected:

	int score; //the lower the better

	GameObjectManager *m_gom;
//	int amount_of_objects;
	std::vector<Collider*> m_object;

};

