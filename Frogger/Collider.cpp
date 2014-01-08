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

		if(fabs(Z) <= Q+P) // ändrar här till =
		{
			float dx = ceilf(fabs(C) - (A+B));
			float dy = ceilf(fabs(Z) - (Q+P));
			if (dx >= dy) // här också
			{
				if (m_position.m_x < p_other.m_position.m_x) //bytte > till < här
				{
					dx = -dx;
				}
				p_offset.m_x = dx;
				//jag ser här att det står p_other.m_position.m_x += dx; 
				//också vettefan varför dock

			}else
			{
				if(m_position.m_y > p_other.m_position.m_y)
				{
					dy = - dy;

				}
				p_offset.m_y = dy;
				//samma här, undrar varför - han += på dx och dy på p_other.m_position.m_y
				// till något men jag vet inte vad han kan ha för användning av detr senare.
				//måste vara att han fixar collision senare med det.
			}

			return true;
		}


	}
	return false;
}
