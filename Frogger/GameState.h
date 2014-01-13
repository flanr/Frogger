// GameState.h


#pragma once
#include "State.h"
#include <SDL.h>
#include "InputManager.h"

class DrawManager;
class Level;
class LevelBackground;
class SpriteManager;
//Ladbon
class PlayerObject;
class GameObject;
class Water;


class GameState : public State
{
	friend class Engine;
public:
	GameState(SDL_Renderer* renderer, InputManager *input, GameObjectManager *manager);
	bool Enter(Engine*);
	void Exit();
	bool Update(float p_deltatime);
	void Draw();
	std::string Next();
	std::string GetCurrentState();
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


	//Ladbon
	PlayerObject* m_player;
	InputManager *m_input;
	Water *m_water;
	Engine *m_engine;
};
