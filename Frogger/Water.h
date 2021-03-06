//Water.h

#include "GameObject.h"

#pragma once

class Sprite;
class Collider;

class Water : public GameObject 
{
public:
	Water(Sprite* sprite = nullptr, Collider* collider = nullptr);
	virtual GameObject_Type GetType();

	void Update(float deltatime);

private:

};