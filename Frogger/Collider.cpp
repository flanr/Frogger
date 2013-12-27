// Collider.cpp


#include <cmath>
#include "Collider.h"

Collider::Collider()
	: m_position(0.0f, 0.0f)
	, m_extension(0.0f, 0.0f)
{

}
Collider::~Collider()
{

}


Collider::Collider(const Vector2 &p_position, const Vector2 &p_extension)
	: m_position(p_extension)
	, m_extension(p_extension)
{

}

bool Collider::Overlap(const Collider &p_other, Vector2 &p_offset)
{
	float A = m_extension.m_x * 0.5f;
	float B = p_other.m_extension.m_x *0.5f;
	float C = (m_position.m_x + A) - (p_other.m_position.m_x + B);

	if(fabs(C) < A+B)
	{
		float Q = m_extension.m_y *0.5f;
		float P = p_other.m_extension.m_y *0.5f;
		float Z = (m_position.m_y + Q ) - ( p_other.m_position.m_y + P);

		if(fabs(Z) < Q+P)
		{
			float dx = ceilf(fabs(C) - (A+B));
			float dy = ceilf(fabs(Z) - (Q+P));
			if (dx>dy)
			{
				if (m_position.m_x > p_other.m_position.m_x)
				{
					dx = -dx;
				}
				p_offset.m_x = dx;

			}else
			{
				if(m_position.m_y > p_other.m_position.m_y)
				{
					dy = - dy;

				}
				p_offset.m_y =dy;
			}

			return true;
		}


	}
	return false;
}
