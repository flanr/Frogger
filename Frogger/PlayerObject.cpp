//PlayerObject.cpp

#include "PlayerObject.h"
#include <cstdio>
#include <SDL.h>
#include "InputManager.h"
#include "GameObjectManager.h"
#include "Sprite.h"
#include "Collider.h"
#include <iostream>
#include "Animation.h"
#include "SoundManager.h"
#include "SoundClip.h"

PlayerObject::PlayerObject(InputManager *control, Sprite* sprite, Collider* collider)
	: GameObject(sprite, collider)
	, m_input(control)
	, m_velocity(0.0f, 0.0f)
{ 
	m_current_animation = nullptr;
	m_direction = "up";
	sound_manager = new SoundManager();
	sound_clip = sound_manager->CreateSound("../data/match.wav");
}

GameObject_Type PlayerObject::GetType()
{
	return PLAYER;
}

void PlayerObject::Update(float deltatime)
{
	m_velocity.m_x = 0.0f;
	m_velocity.m_y = 0.0f;
	float movespeed = 70.0f;

	if(m_input->IsDownOnce(SDLK_a))
	{
		sound_clip->Play();
		m_direction = "left";
		SetAnimation("Player_Move_Left");
		m_velocity.m_x -= movespeed;

	}
	if(m_input->IsDownOnce(SDLK_d))
	{
		sound_clip->Play();
		m_direction = "right";
		SetAnimation("Player_Move_Right");
		m_velocity.m_x += movespeed;

	}
	if(m_input->IsDownOnce(SDLK_w))
	{
		sound_clip->Play();
		m_direction = "up";
		SetAnimation("Player_Move");
		m_velocity.m_y -= movespeed;

	}
	if(m_input->IsDownOnce(SDLK_s))
	{	
		sound_clip->Play();
		m_direction = "down";
		SetAnimation("Player_Move_Down");
		m_velocity.m_y += movespeed;
	}
	if(m_input->IsUp(SDLK_a) && m_input->IsUp(SDLK_d) && m_input->IsUp(SDLK_w) && m_input->IsUp(SDLK_s))
	{
		if(m_direction == "up")
		{ SetAnimation("Player_Moving_Still"); }
		else if(m_direction == "down")
		{ SetAnimation("Player_Moving_Still_Down"); }
		else if(m_direction == "left")
		{ SetAnimation("Player_Moving_Still_Left"); }
		else if(m_direction == "right")
		{ SetAnimation("Player_Moving_Still_Right"); }
	}

	m_position += m_velocity;

	if(HasCollider()) {
		m_collider->m_position = m_position;
	};
}

void PlayerObject::AddAnimation(const std::string &name, Animation *sprite)
{
	m_animation.insert(std::pair<std::string, Animation*>(name, sprite));

	if(m_sprite == nullptr)
	{
		m_sprite = sprite;
		m_current_animation = sprite;
	}
}

void PlayerObject::SetAnimation(std::string name)
{
	auto xIt = m_animation.begin();
	while(xIt != m_animation.end())
	{
		if(xIt->first == name)
		{
			m_sprite = xIt->second;
			m_current_animation = xIt->second;
		}
		xIt++;
	}
}
