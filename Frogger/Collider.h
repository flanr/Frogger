// Collider.h


#pragma once
#include "Vector2.h"

class GameObject;

class Collider
{
public:
	Collider();
	Collider(const Vector2 &p_position, const Vector2 &p_exstension);
	~Collider();

	bool Overlap(const Collider &p_other, Vector2 &p_offset);
	void NotifyParent(GameObject* go1);

	GameObject *m_xobject; //min collider en pekare till ett gameobject
	Vector2 m_position;
	Vector2 m_extension;
private:

};