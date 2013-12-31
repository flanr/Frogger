// GameState.cpp

#include "GameState.h"
#include <iostream>
#include "Level.h"
#include "DrawManager.h"
#include "SpriteManager.h"
#include "Engine.h"

GameState::GameState(SDL_Renderer* renderer)
{
	this->renderer = renderer;
	m_draw_manager = nullptr;
	m_level = nullptr;
	// bool GameStateRunning = false;
}

bool GameState::Enter(Engine* engine)
{
	std::cout << "GameState::Enter" << std::endl;
	// GameStateRunning = true:
	m_draw_manager = engine->m_draw_manager;
	/*m_draw_manager = new DrawManager;*/
	/*if(!m_draw_manager->Initialize(engine->m_window,engine->m_width,engine->m_height))
	{
		return false;	
	}*/
	m_sprite_manager = new SpriteManager(m_draw_manager);
	if(!m_sprite_manager ->Initialize("../data/sprites/"))
	{
		return false;
	}

	m_level = new Level;
	m_level->Load("../data/levels/level.txt",m_sprite_manager);
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
	
	m_draw_manager->Clear();
	m_level->Draw(m_draw_manager);

	
}


std::string GameState::Next()
{
	return "MenuState";
}

bool GameState::IsType(const std::string &p_type)
{
	return p_type.compare("GameState") == 0;
}


