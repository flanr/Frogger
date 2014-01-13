// GameObject.h

#pragma once
#include "Vector2.h"
#include "GameObjectManager.h"

class Sprite;
class Collider;
class GameObject
{
public:
	GameObject(Sprite *sprite=nullptr, Collider *collider = nullptr);
	virtual GameObject_Type GetType();

	const Vector2  &GetPosition() const;
	void SetPosition(const Vector2 &p_position);

	bool HasSprite() const;
	Sprite* GetSprite();

	bool HasCollider() const;
	Collider* GetCollider();

	virtual void Update(float deltatime);

	~GameObject();

protected:
	Vector2 m_position;
	Sprite *m_sprite;
	Collider *m_collider;

};
