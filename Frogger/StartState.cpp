// StartState.cpp

#include "StartState.h"
#include "Engine.h"
#include <iostream>
#include "GameObjectManager.h"
#include "InputManager.h"
#include "Engine.h"
#include <stdio.h>
#include "Button.h"
#include "Sprite.h"
#include "SpriteManager.h"
#include "DrawManager.h"

StartState::StartState(SDL_Renderer* renderer, InputManager *input, GameObjectManager *manager)
{
	this->renderer = renderer;
	m_input = input;
	m_manager = manager;
	Start.SetButton(500,470, 100,100);
	Options.SetButton(400, 600, 100, 100);
	// bool MenuStateRunning = false;
}

bool StartState::Enter(Engine* engine)
{
	m_engine =engine;
	backgroundImg = m_engine->m_sprite_manager->Load("froggerbg.png",0,0,720,720);
	plaYImg = m_engine->m_sprite_manager->Load("plaY.png",0,0,100,100);
	optionImg = m_engine->m_sprite_manager->Load("settings.png",0,0,100,100);
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
	
	if (m_input->IsDown(MB_LEFT))
	{
		mouseDown(m_input->GetX(),m_input->GetY());
	}

}
int StartState::mouseOver(int x, int y)
{
	if ((x > Start.GetX() && x <Start.GetX()+ Start.GetW()) && (y > Start.GetY() && y < Start.GetY()+ Start.GetH())){
		return 1;
	}
	else if ((x > Options.GetX() && x <Options.GetX()+ Options.GetW()) && (y > Options.GetY() && y < Options.GetY()+ Options.GetH())){
		return 2;
	}
	else{
		return 0;
	}
}
void StartState::mouseDown(int x, int y)
{
	if(mouseOver(x,y) == 1)
	{
		
		m_engine->m_state_manager.SetState("GameState");

	}
	if(mouseOver(x,y) == 2)
	{
		
		m_engine->m_state_manager.SetState("MenuState");

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
	//Options.SetX((Options.GetX() + 5) % m_engine->GetWidth());
	//Start.SetX((Start.GetX() + 5) % m_engine->GetWidth());
	m_engine->m_draw_manager->Draw(backgroundImg,0,0);
	m_engine->m_draw_manager->Draw(plaYImg,Start.GetX(),Start.GetY());
	m_engine->m_draw_manager->Draw(optionImg,Options.GetX(),Options.GetY());
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

