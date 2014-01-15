// StartState.h

#pragma once
#include "State.h"
#include "Engine.h"
#include <SDL.h>
#include "Menu.h"

class InputManager;
class Engine;
class StartState : public State

{
public:
	StartState(SDL_Renderer* renderer, InputManager *input, GameObjectManager *manager);
	bool Enter(Engine*);
	void Exit();
	bool Update(float p_deltatime);
	void Draw();
	std::string GetCurrentState();
	std::string Next();
	void HandleInput();
	bool mouseOver(int x, int y);
	void mouseDown(int x, int y);
	void moveMouse(int x, int y);
	/**
	Returns True if p_type == GameState
	**/
	bool IsType(const std::string &p_type);

private:
	bool selected;
	bool hovered;
	bool m_done;
	Engine* m_engine;
	InputManager* m_input;
	std::string m_state_next;
	SDL_Renderer* renderer;
	SDL_Rect startbutton;


};
