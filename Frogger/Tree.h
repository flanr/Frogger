//Tree.h

#pragma once

#include "GameObject.h"

class Sprite;
class Collider;


//class AnimatedSprite;


class Tree  : public GameObject
{
public:

	Tree(Sprite* sprite = nullptr, Collider* collider = nullptr);

	virtual GameObject_Type GetType();

	void Update(float deltatime);



	//	void AddAnimation(const std::string &name, AnimatedSprite *sprite);

protected:
	
	Vector2 m_velocity;
	float m_movespeed;
	float m_direction;

	//	AnimatedSprite *m_current_animation;
	//std::map<std::string, AnimatedSprite*> m_animation;
}; 