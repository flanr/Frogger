// GameState.h


#pragma once

#include "State.h"
#include <SDL.h>
#include "Input.h"



class DrawManager;
class Level;
class LevelBackground;
class SpriteManager;
class PlayerObject;
class GameObject;


class GameState : public State
{
	friend class Engine;
public:

	GameState(SDL_Renderer* renderer, Keyboard *keyboard, Mouse *mouse, GameObjectManager *manager);
	bool Enter(Engine*);
	void Exit();
	bool Update(float p_deltatime);
	void Draw();	
	std::string Next();
	/**
	Returns True if p_type == GameState
	**/
	bool IsType(const std::string &p_type);

private:


	bool m_done;
	std::string m_state_next;
	SDL_Renderer* renderer;
	DrawManager* m_draw_manager;
	SpriteManager* m_sprite_manager;
	Level* m_level;
	LevelBackground *m_levelbackground;
	PlayerObject* m_player;
	Keyboard *m_keyboard;
	Mouse *m_mouse;
	Engine *m_engine;

};
