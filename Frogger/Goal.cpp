//Goal.cpp


#include "Goal.h"
#include "GameObject.h"
#include "Collider.h"

Goal::Goal(Sprite* sprite, Collider* collider)
	: GameObject(sprite, collider)
{

}
GameObject_Type Goal::GetType()
{
	return GOAL;
}

void Goal::Update(float deltatime)
{
		if(HasCollider()) {
		m_collider->m_position = m_position;
	};
}