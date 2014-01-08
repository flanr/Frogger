// BackgroundObject.cpp

#include "BackgroundObject.h"

BackgroundObject::BackgroundObject(Sprite *p_sprite)
	:m_position(0.0f, 0.0f)
	, m_sprite(p_sprite)
{

}
BackgroundObject::~BackgroundObject()
{

}
const Vector2 &BackgroundObject::GetPosition() const
{
	return m_position;
}
void BackgroundObject::SetPosition(const Vector2 &p_position)
{
	m_position = p_position;
}
bool BackgroundObject::HasSprite() const
{
	return m_sprite != nullptr;
}
Sprite* BackgroundObject::GetSprite()
{
	return m_sprite;
}

