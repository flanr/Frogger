// MenuState.h

#pragma once
#include "State.h"
#include "Engine.h"
#include <SDL.h>
#include "Menu.h"

class InputManager;


class MenuState : public State
	//FLAN
{
public:
	MenuState(SDL_Renderer* renderer, InputManager *input, Engine* engine);
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
	InputManager *m_input;


	std::string m_state_next;
	SDL_Renderer* renderer;
	Menu* menu;


};
