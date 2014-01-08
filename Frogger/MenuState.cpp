// MenuState.cpp

#include "MenuState.h"
#include "Engine.h"
#include <iostream>
#include "Menu.h"
#include "GlobalGameConfig.h"
MenuState::MenuState(SDL_Renderer* renderer)
{
	this->renderer = renderer;
	
	// bool MenuStateRunning = false;
}

bool MenuState::Enter(Engine* engine)
{
	int menuX = engine->m_width/2;
	int menuY = engine->m_height/2;
	menu = new Menu(engine->m_width/2-(menuX/2), engine->m_height/2-(menuY/2), menuX, menuY );
	// MenuStateRunning = true:
	std::cout << "MenuState now running" << std::endl;
	return false;
}

void MenuState::Exit()
{

}

bool MenuState::Update(float p_deltatime)
{
	menu->Run(renderer);
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


