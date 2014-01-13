// PlayerObject.h

//#include "map"
#include "GameObject.h"

#pragma once

class InputManager;
class Sprite;
class Collider;

//class AnimatedSprite;

class PlayerObject : public GameObject {
public:

	PlayerObject(InputManager *control, Sprite* sprite = nullptr, Collider* collider = nullptr);
	virtual GameObject_Type GetType();

	void Update(float deltatime);
//	void AddAnimation(const std::string &name, AnimatedSprite *sprite);

protected:

	InputManager* m_input;
	Vector2 m_velocity;
//	AnimatedSprite *m_current_animation;
	//std::map<std::string, AnimatedSprite*> m_animation;
};
