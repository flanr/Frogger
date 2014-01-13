// StartState.cpp

#include "StartState.h"
#include "Engine.h"
#include <iostream>
#include "GameObjectManager.h"
#include "InputManager.h"
#include "Engine.h"

StartState::StartState(SDL_Renderer* renderer, InputManager *input, GameObjectManager *manager)
{
	this->renderer = renderer;
	startbutton.x = 290;
	startbutton.y = 290;
	startbutton.w = 100;
	startbutton.h = 100;
	m_input = input;
	m_manager = manager;
	// bool MenuStateRunning = false;
}

bool StartState::Enter(Engine* engine)
{
	m_engine =engine;
	m_Current_State = "StartState";
	std::cout << "StartState now running" << std::endl;
	return false;
}
std::string StartState::GetCurrentState()
{
	return m_Current_State;
}

void StartState::Exit()
{

}
void StartState::HandleInput()
{
	if (m_input->IsDownOnce(SDLK_k))
	{
		m_engine->m_state_manager.SetState("GameState");
	}
}


bool StartState::Update(float p_deltatime)
{

	//menu->Run(renderer);

	SDL_Delay(10);
	HandleInput();
	//SDL_RenderPresent(renderer);
	//m_manager->Update(p_deltatime);

	return true;

}

void StartState::Draw()
{
	SDL_SetRenderDrawColor(renderer, 255,0,0,0xff);
	SDL_RenderFillRect(renderer, &startbutton);

	//SDL_RenderClear(renderer);
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

