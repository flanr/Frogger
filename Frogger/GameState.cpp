// GameState.cpp

#include "GameState.h"
#include <iostream>


GameState::GameState(SDL_Renderer* renderer)
{
	this->renderer = renderer;
	// bool GameStateRunning = false;
}

bool GameState::Enter()
{
	// GameStateRunning = true:
	
	std::cout << "GameState now running" << std::endl;
	return false;
}

void GameState::Exit()
{

}

bool GameState::Update(float p_deltatime)
{
	
	return true;
}

void GameState::Draw()
{
	SDL_SetRenderDrawColor(renderer, 255,0,255,0xff);
	SDL_RenderClear(renderer);
}


std::string GameState::Next()
{
	return "MenuState";
}

bool GameState::IsType(const std::string &p_type)
{
	return p_type.compare("GameState") == 0;
}


