// GameState.cpp

#include "GameState.h"
#include <iostream>


GameState::GameState()
{

	// bool GameStateRunning = false;
}

bool GameState::Enter()
{
	// GameStateRunning = true:
	
	std::cout << "GameState now running";
	return false;
}

void GameState::Exit()
{

}

bool GameState::Update(float p_deltatime)
{

	return false;
}

void GameState::Draw()
{
	
}


std::string GameState::Next()
{
	return "MenuState";
}

bool GameState::IsType(const std::string &p_type)
{
	return p_type.compare("GameState") == 0;
}


