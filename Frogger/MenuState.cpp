// MenuState.cpp

#include "MenuState.h"
#include <iostream>

MenuState::MenuState(SDL_Renderer* renderer)
{
	this->renderer = renderer;
	// bool MenuStateRunning = false;
}

bool MenuState::Enter()
{
	// MenuStateRunning = true:
	std::cout << "MenuState now running" << std::endl;
	return false;
}

void MenuState::Exit()
{

}

bool MenuState::Update(float p_deltatime)
{
	return true;
}

void MenuState::Draw()
{
	SDL_SetRenderDrawColor(renderer, 255,0,0,0xff);
	SDL_RenderClear(renderer);
}


std::string MenuState::Next()
{
return "GameState";
}

bool MenuState::IsType(const std::string &p_type)
{
	//return false;
	return p_type.compare("MenuState") == 0;
}


