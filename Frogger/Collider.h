// Collider.h


#pragma once
#include "Vector2.h"

class Collider
{
public:
	Collider();
	Collider(const Vector2 &p_position, const Vector2 &p_exstension);
	~Collider();

	bool Overlap(const Collider &p_other, Vector2 &p_offset);

	Vector2 m_position;
	Vector2 m_extension;
private:

};