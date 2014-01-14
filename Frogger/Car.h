//Car.h

#pragma once

#include "GameObject.h"

class Sprite;
class Collider;

//class AnimatedSprite;


class Car  : public GameObject
{
public:

	Car(Sprite* sprite = nullptr, Collider* collider = nullptr);
	
	virtual GameObject_Type GetType();

	void Update(float deltatime);

	//	void AddAnimation(const std::string &name, AnimatedSprite *sprite);

private:
	Vector2 m_velocity;
	float movespeed;
		//	AnimatedSprite *m_current_animation;
	//std::map<std::string, AnimatedSprite*> m_animation;
};
