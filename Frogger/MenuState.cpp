// MenuState.cpp

#include "MenuState.h"
#include "Engine.h"
#include <iostream>
<<<<<<< HEAD
#include "Menu.h"
#include "GlobalGameConfig.h"

MenuState::MenuState(SDL_Renderer* renderer)
=======
#include "GameObjectManager.h"

MenuState::MenuState(SDL_Renderer* renderer, Keyboard *keyboard, Mouse *mouse, GameObjectManager *manager)
>>>>>>> 3f9ee28b9ec02a57b1d1676f76af395488feabee
{
	this->renderer = renderer;
	// bool MenuStateRunning = false;
	m_keyboard = keyboard;
	m_mouse = mouse;
	m_manager = manager;
}

bool MenuState::Enter(Engine* engine)
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
	m_manager->Update(p_deltatime);

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


