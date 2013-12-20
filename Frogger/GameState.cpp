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
	return "";
}

bool GameState::IsType(const std::string &p_type)
{
	return false;
	//return p_type.compare("GameState") == 0;
}


