//Water.h

#include "GameObject.h"

#pragma once

class InputManager;
class Sprite;
class Collider;

class Water : public GameObject 
{
public:
	Water(Sprite* sprite = nullptr, Collider* collider = nullptr);
	
	void Update(float deltatime);

private:

};