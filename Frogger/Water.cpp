//Water.cpp

#include "Water.h"
#include "GameObject.h"

Water::Water(Sprite* sprite, Collider* collider)
	: GameObject(sprite, collider)
{

}

void Water::Update(float deltatime)
{

}	

GameObject_Type Water::GetType()
{
	return WATER;
}