// PlayerObject.h

#include "map"
#include "GameObject.h"

#pragma once

class InputManager;
class Sprite;
class Collider;
class Tree;
class Animation;

class PlayerObject : public GameObject {
public:

	PlayerObject(InputManager *control, Sprite* sprite = nullptr, Collider* collider = nullptr);
	virtual GameObject_Type GetType();

	void Update(float deltatime);
	void AddAnimation(const std::string &name, Animation *sprite);

protected:
	
	
	InputManager* m_input;
	Vector2 m_velocity;
	Animation *m_current_animation;
	std::map<std::string, Animation*> m_animation;
};
