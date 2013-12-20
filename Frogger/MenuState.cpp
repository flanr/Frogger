// MenuState.cpp

#include "MenuState.h"
#include <iostream>

MenuState::MenuState()
{
	// bool MenuStateRunning = false;
}

bool MenuState::Enter()
{
	// MenuStateRunning = true:
	std::cout << "menu state now running";
	return false;
}

void MenuState::Exit()
{

}

bool MenuState::Update(float p_deltatime)
{
	return false;
}

void MenuState::Draw()
{

}


std::string MenuState::Next()
{
return "";
}

bool MenuState::IsType(const std::string &p_type)
{
	//return false;
	return p_type.compare("MenuState") == 0;
}


