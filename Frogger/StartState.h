// StartState.h

#pragma once
#include "State.h"
#include "Engine.h"
#include <SDL.h>
#include "Menu.h"
#include "Button.h"

class InputManager;
class Engine;
class Sprite;
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
	int mouseOver(int x, int y);
	void mouseDown(int x, int y);
	/**
	Returns True if p_type == GameState
	**/
	bool IsType(const std::string &p_type);

private:
	bool m_done;
	Button Start;
	Button Options;
	Engine* m_engine;
	InputManager* m_input;
	std::string m_state_next;
	SDL_Renderer* renderer;
	SDL_Rect startbutton;
	Sprite *backgroundImg;
	Sprite *plaYImg;
	Sprite *optionImg;
};
