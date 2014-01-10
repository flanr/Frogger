//GameObjectManager.h

#pragma once

enum TYPE
{
	PLAYER,
	WATER,
	CAR,
	LOG,
	TURTLE,
	GOAL
};

#include <vector>

class GameState;
class GameObject;
class DrawManager;

class GameObjectManager
{
public:

	GameObjectManager();
	~GameObjectManager();

	//Update
	void Update(float deltatime);
	//attach 
	void AttachObject(GameObject *object);
	//detach
	void DetachObject(GameObject *object);
	void DetachObject();
	//draw
	void DrawObject(DrawManager *draw);

private:
	std::vector<GameObject*> m_gameobject;

};