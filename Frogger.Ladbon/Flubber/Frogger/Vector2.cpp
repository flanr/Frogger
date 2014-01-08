// Vector2.cpp
#include "Vector2.h"
#include <cmath>


Vector2::Vector2()
{
	m_x = 0.0f;
	m_y = 0.0f;
}

Vector2::Vector2(const Vector2 &p_rhs)
{
	m_x = p_rhs.m_x;
	m_y = p_rhs.m_y;
}

Vector2::Vector2(float p_x, float p_y)
{
	m_x = p_x;
	m_y = p_y;
}

Vector2 &Vector2::operator=(const Vector2 &p_rhs)
{
	m_x = p_rhs.m_x;
	m_y = p_rhs.m_y;
	return *this;
}

Vector2 Vector2::operator+=(const Vector2 &p_rhs)
{
	m_x += p_rhs.m_x;
	m_y += p_rhs.m_y;
	return *this;
}

Vector2 Vector2::operator-=(const Vector2 &p_rhs)
{
	m_x -= p_rhs.m_x;
	m_y -= p_rhs.m_y;
	return *this;
}
Vector2 Vector2::operator*=(float p_value)
{
	m_x *= p_value;
	m_y *= p_value;
	return *this;
}
Vector2 Vector2::operator/=(float p_value)
{
	m_y /= p_value;
	m_y /= p_value;
	return *this;
}

Vector2 Vector2::operator+(const Vector2 &p_rhs)
{
	return Vector2(m_x + p_rhs.m_x, m_y + p_rhs.m_y);
}
Vector2 Vector2::operator-(const Vector2 &p_rhs)
{
	return Vector2(m_x - p_rhs.m_x, m_y - p_rhs.m_y);
}
Vector2 Vector2::operator*(float p_value)
{
	return Vector2(m_x * p_value, m_y * p_value);
}
Vector2 Vector2::operator/(float p_value)
{
	return Vector2(m_x / p_value, m_y / p_value);
}
bool Vector2::operator==(const Vector2 &p_rhs)
{
	const float epsilon = 0.00001f;
	return fabs(m_x - p_rhs.m_x) < epsilon && fabs(m_y - p_rhs.m_y) < epsilon;
}
bool Vector2::operator!=(const Vector2 &p_rhs)
{
	return !(*this==p_rhs);
}



float Vector2::Lenght()
{
	return sqrtf(m_x * m_x + m_y * m_y);
}

void Vector2::Normalize()
{
	float length = Lenght();
	if (length > 0.0f)
	{
		m_x /= length;
		m_y /= length;
	}

}


Vector2::~Vector2()
{
}