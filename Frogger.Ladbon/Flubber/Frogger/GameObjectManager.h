//GameObjectManager.h

#pragma once

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
	//draw
	void DrawObject(DrawManager *draw);

private:
	std::vector<GameObject*> m_gameobject;

};