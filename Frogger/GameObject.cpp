// GameObject.cpp

#include "GameObject.h"
#include <iostream>
#include "Collider.h"
#include <iostream>


GameObject::GameObject(Sprite *p_sprite, Collider *p_collider)
	: m_position(0.0f, 0.0f)
	, m_sprite(p_sprite)
	, m_collider(p_collider)
{
	m_collider->m_xobject = this;
	m_is_on_log = false;
}
GameObject::~GameObject()
{

}
void GameObject::SetStartPosition(const Vector2 &p_position)
{
	m_position_start = p_position;
}
Vector2 GameObject::GetStartPosition()
{
	return m_position_start;
}

void GameObject::Update(float deltatime)
{

}
const Vector2 &GameObject::GetPosition() const
{
	return m_position;
}

void GameObject::SetPosition(const Vector2 &p_position)
{
	m_position = p_position;
}

bool GameObject::HasSprite() const
{
	return m_sprite !=nullptr;
}

Sprite* GameObject::GetSprite()
{
	return m_sprite;
}

bool GameObject::HasCollider() const
{
	return m_collider !=nullptr;
}

Collider* GameObject::GetCollider()
{
	return m_collider;
}

GameObject_Type GameObject::GetType()
{
	return GAMEOBJ;
}



