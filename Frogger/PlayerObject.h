// PlayerObject.h

#include "map"
#include "GameObject.h"
#include <string>

#pragma once

class InputManager;
class Sprite;
class Collider;
class Tree;
class Animation;
class SoundClip;
class SoundManager;

class PlayerObject : public GameObject {
public:

	PlayerObject(InputManager *control, Sprite* sprite = nullptr, Collider* collider = nullptr);
	virtual GameObject_Type GetType();

	void Update(float deltatime);
	void AddAnimation(const std::string &name, Animation *sprite);
	void SetAnimation(std::string name);
	
	std::string m_direction;
protected:
	SoundManager* sound_manager;
	SoundClip* sound_clip;
	InputManager* m_input;
	Vector2 m_velocity;
	Animation *m_current_animation;
	std::map<std::string, Animation*> m_animation;
};
