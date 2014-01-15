// StartState.cpp

#include "StartState.h"
#include "Engine.h"
#include <iostream>
#include "GameObjectManager.h"
#include "InputManager.h"
#include "Engine.h"
#include <stdio.h>
#include "Button.h"

StartState::StartState(SDL_Renderer* renderer, InputManager *input, GameObjectManager *manager)
{
	this->renderer = renderer;
	startbutton.x = 290;
	startbutton.y = 290;
	startbutton.w = 100;
	startbutton.h = 100;
	m_input = input;
	m_manager = manager;
	selected = false;
	selected = false;
	Start.SetButton(500, 290, 100,100);
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
	moveMouse(m_input->GetX(),m_input->GetY());
	if (m_input->IsDown(MB_LEFT))
	{
		mouseDown(m_input->GetX(),m_input->GetY());
	}

}
bool StartState::mouseOver(int x, int y)
{
	return (x > startbutton.x && x <startbutton.x+ startbutton.w) && (y > startbutton.y && y < startbutton.y+ startbutton.h);
}
void StartState::mouseDown(int x, int y)
{
	if(mouseOver(x,y))
	{
		selected = true;
		
		m_engine->m_state_manager.SetState("GameState");
		moveMouse(x, y);
	}

}
void StartState::moveMouse(int x, int y)
{
	if(mouseOver(x,y))
	{
		hovered = true;
	}
	else
	{
		selected = false;
		hovered = false;
	}

	if (selected)
	{
		printf("X:[%d]Y: [%d]\r\n", x, y);
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
	SDL_RenderFillRect(renderer, &Start.GetButton());

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

