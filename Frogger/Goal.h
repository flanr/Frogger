//Goal.h

#pragma once

#include "GameObject.h"


class Sprite;
class Collider;

class Goal : public GameObject 
{
public:
	
	Goal(Sprite* sprite = nullptr, Collider* collider = nullptr);
	virtual GameObject_Type GetType();

	void Update(float deltatime);

private:

};