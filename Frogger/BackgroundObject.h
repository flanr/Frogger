// BackgroundObject.h

#pragma once
#include "Vector2.h"

class Sprite;
class BackgroundObject
{
public:
	BackgroundObject(Sprite *p_sprite=nullptr);
	~BackgroundObject();

	const Vector2 &GetPosition() const;
	void SetPosition(const Vector2 &p_position);

	bool HasSprite() const;
	Sprite* GetSprite();



private:
	Vector2 m_position;
	Sprite *m_sprite;

};
