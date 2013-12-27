// Vector2.h

#pragma once


class Vector2
{
public:
	Vector2();
	Vector2(const Vector2 &p_rhs);
	Vector2(float p_x, float p_y);
	~Vector2();

	Vector2 &operator=(const Vector2 &p_rhs);
	Vector2 operator+=(const Vector2 &p_rhs);
	Vector2 operator-=(const Vector2 &p_rhs);
	Vector2 operator*=(float p_value);
	Vector2 operator/=(float p_value);

	Vector2 operator+(const Vector2 &p_rhs);
	Vector2 operator-(const Vector2 &p_rhs);
	Vector2 operator*(float p_value);
	Vector2 operator/(float p_value);

	bool operator==(const Vector2 &p_rhs);
	bool operator!=(const Vector2 &p_rhs);

	float Lenght();
	void Normalize();

	


	float m_x;
	float m_y;

};

