// PlayerObject.h

//#include "map"
#include "GameObject.h"

#pragma once

class Keyboard;
class Sprite;
class Collider;
class Mouse;
//class AnimatedSprite;

class PlayerObject : public GameObject {
public:

	PlayerObject(Keyboard *keyboard, Sprite* sprite = nullptr, Collider* collider = nullptr);
	
	void Update(float deltatime);
//	void AddAnimation(const std::string &name, AnimatedSprite *sprite);

protected:

	Keyboard* m_keyboard;
	Vector2 m_velocity;
//	AnimatedSprite *m_current_animation;
	//std::map<std::string, AnimatedSprite*> m_animation;
};
