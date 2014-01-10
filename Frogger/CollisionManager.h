//CollisionManager.h


#pragma once

#include <vector>

class GameObject;

class CollisionManager
{
public:
	CollisionManager(std::vector<GameObject*> *m_object);
	~CollisionManager();

	bool Collided();
	void HasCollided(GameObject *Object1, GameObject *Object2);


private:
	std::vector<GameObject*> m_object;

};

