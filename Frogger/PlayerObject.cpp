//PlayerObject.cpp

#include "PlayerObject.h"
#include <cstdio>
#include <SDL.h>
#include "InputManager.h"
#include "Sprite.h"
#include "Collider.h"
#include <iostream>

PlayerObject::PlayerObject(InputManager *control, Sprite* sprite, Collider* collider)
	: GameObject(sprite, collider)
	, m_input(control)
	, m_velocity(0.0f, 0.0f)
{ 
//	m_current_animation = nullptr;7
}
void PlayerObject::Update(float deltatime)
{
	m_velocity.m_x = 0.0f;
	m_velocity.m_y = 0.0f;
	float movespeed = 70.0f;

	if(m_input->IsDownOnce(SDLK_a))
	{
		std::cout << "a\n";
		m_velocity.m_x -= movespeed;
	}
	if(m_input->IsDownOnce(SDLK_d))
	{
		m_velocity.m_x += movespeed;
	}
	if(m_input->IsDownOnce(SDLK_w))
	{
		m_velocity.m_y -= movespeed;
	}
	if(m_input->IsDownOnce(SDLK_s))
	{	
		m_velocity.m_y += movespeed;
	}

	m_position += m_velocity;

}
//void PlayerObject::AddAnimation(const std::string &name, AnimatedSprite *sprite)
//{
	//m_animation.insert(std::pair<std::string, AnimatedSprite*>(name, sprite));	
//}
