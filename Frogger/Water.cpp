//Water.cpp

#include "Water.h"
#include "GameObject.h"
#include "Collider.h"

Water::Water(Sprite* sprite, Collider* collider)
	: GameObject(sprite, collider)
{

}

void Water::Update(float deltatime)
{
		if(HasCollider()) {
		m_collider->m_position = m_position;
	};
}	

GameObject_Type Water::GetType()
{
	return WATER;
}