// MenuState.h

#pragma once
#include "State.h"
#include "Engine.h"
#include <SDL.h>
#include "Menu.h"
#include "Button.h"

class InputManager;
class Engine;
class Sprite;

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
	int mouseOver(int x, int y);
	void mouseDown(int x, int y);
	/**
	Returns True if p_type == GameState
	**/
	bool IsType(const std::string &p_type);
	void HandleInput();


private:
	bool m_done;
	InputManager *m_input;

	Engine* m_engine;
	std::string m_state_next;
	SDL_Renderer* renderer;
	Menu* menu;

	Button Play_btn;
	Sprite* Play_sprite;
	Button Stop_btn;
	Sprite* Stop_sprite;
	Button Next_btn;
	Sprite* Next_sprite;
	Button Prev_btn;
	Sprite* Prev_sprite;
	Button StartState_btn;
	Sprite* StartState_sprite;
	Button GameState_btn;
	Sprite* GameState_sprite;

};
