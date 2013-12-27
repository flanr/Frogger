// GameState.h


#pragma once
#include "State.h"
#include <SDL.h>

class GameState : public State
{
public:
	GameState(SDL_Renderer* renderer);
	bool Enter();
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
};
