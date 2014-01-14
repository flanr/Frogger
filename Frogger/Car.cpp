#include "Car.h"	
#include <cstdio>
#include <SDL.h>
#include "GameObjectManager.h"
#include "Sprite.h"
#include "Collider.h"
#include <iostream>

Car::Car(Sprite* sprite, Collider* collider)
	: GameObject(sprite, collider)
	, m_velocity(0.0f, 0.0f)
{

}
GameObject_Type Car::GetType()
{
	return CAR;
}
void Car::Update(float deltatime)
{
	movespeed = deltatime + 2;

	if(m_position .m_x != 720)
	{
		m_velocity.m_x += movespeed;
	}

	m_position = m_velocity;

	if(HasCollider()) {
		m_collider->m_position = m_position;
	};
}