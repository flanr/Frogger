//Tree.cpp

#include "Tree.h"
#include <cstdio>
#include <SDL.h>
#include "GameObjectManager.h"
#include "Sprite.h"
#include "Collider.h"
#include <iostream>
#include "GameObject.h"



Tree::Tree(Sprite* sprite, Collider* collider)
	: GameObject(sprite, collider)
	, m_velocity(0.0f, 0.0f)
{
	m_movespeed = rand() %50+600.0f;

	m_direction = 0.0f;
	

	if(m_collider->m_position.m_x < 360)
	{
		m_direction = 1;
	}
	else
	{
		m_direction = -1;
	}
}

GameObject_Type Tree::GetType()
{
	return LOG;
}

void Tree::Update(float deltatime)
{
	m_velocity.m_x = m_movespeed * deltatime * m_direction;

	m_position += m_velocity;

	if(m_position.m_x <-140)
	{
		m_position = GetStartPosition();
	}
	if(m_position.m_x > 860)
	{
		m_position = GetStartPosition();
	}

	if(HasCollider()) {
		m_collider->m_position = m_position;
	};
}


//	void AddAnimation(const std::string &name, AnimatedSprite *sprite);