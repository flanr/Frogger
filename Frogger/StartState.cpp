// StartState.cpp

#include "StartState.h"
#include "Engine.h"
#include <iostream>
#include "GameObjectManager.h"


StartState::StartState(SDL_Renderer* renderer, Keyboard *keyboard, Mouse *mouse, GameObjectManager *manager)
{
	this->renderer = renderer;

	m_keyboard = keyboard;
	m_mouse = mouse;
	m_manager = manager;
	// bool MenuStateRunning = false;
}

bool StartState::Enter(Engine* engine)
{
	
	std::cout << "StartState now running" << std::endl;
	return false;
}

void StartState::Exit()
{

}

bool StartState::Update(float p_deltatime)
{

	//menu->Run(renderer);

	SDL_Delay(10);
	SDL_RenderPresent(renderer);
	m_manager->Update(p_deltatime);

	return true;

}

void StartState::Draw()
{
	
	SDL_SetRenderDrawColor(renderer, 255,0,0,0xff);
	SDL_RenderClear(renderer);
}


std::string StartState::Next()
{
	return "GameState";
}

bool StartState::IsType(const std::string &p_type)
{
	//return false;
	return p_type.compare("StartState") == 0;
}

