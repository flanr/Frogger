//GameObjectManager.h

#pragma once

enum GameObject_Type{
	GAMEOBJ,
	PLAYER,
	WATER,
	CAR,
	LOG,
	TURTLE,
	GOAL,
	BACKGROUND 
};

#include <vector>

class GameState;
class GameObject;
class DrawManager;
class Engine;
class Vector2;

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
	//Get_Start_Position
	Vector2 GetStartPosition(GameObject *GO);
	//draw
	void DrawObject(DrawManager *draw);
private:
	std::vector<GameObject*> m_gameobject;

};