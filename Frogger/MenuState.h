// MenuState.h

#pragma once
#include "State.h"
#include "Engine.h"
#include <SDL.h>

class MenuState : public State
{
public:
	MenuState(SDL_Renderer* renderer);
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

};
