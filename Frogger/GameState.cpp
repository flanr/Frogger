// GameState.cpp

#include "GameState.h"
#include <iostream>
#include "Level.h"
#include "LevelBackground.h"
#include "DrawManager.h"
#include "SpriteManager.h"
#include "Engine.h"
#include "Collider.h"
#include "InputManager.h"
#include "Sprite.h"
#include "GameObject.h"
#include "GameObjectManager.h"
#include "CollisionManager.h"
#include "Sprite.h"
#include "Collider.h"


GameState::GameState(SDL_Renderer* renderer, InputManager *input, GameObjectManager *manager)
{
	this->renderer = renderer;
	m_draw_manager = nullptr;
	m_level = nullptr;
	m_input = input;
	m_collmgr = nullptr;
	m_collider = nullptr;
	m_sprite_manager = nullptr;
	m_sprite = nullptr;
	m_manager = manager;

	// bool GameStateRunning = false;
}
std::string GameState::GetCurrentState()
{
	return m_Current_State;
}

bool GameState::Enter(Engine* engine)
{
	m_Current_State = "GameState";
	m_engine = engine;

	std::cout << "GameState::Enter" << std::endl;

	if (m_collmgr ==nullptr)
	{
		m_collmgr = new CollisionManager;
	}

	// GameStateRunning = true:


	if (m_manager == nullptr)
	{
		m_manager = new GameObjectManager;
	}


	m_draw_manager = engine->m_draw_manager;


	/*m_draw_manager = new DrawManager;*/
	/*if(!m_draw_manager->Initialize(engine->m_window,engine->m_width,engine->m_height))
	{
	return false;	
	}*/


	if (m_sprite_manager == nullptr)
	{
		m_sprite_manager = new SpriteManager(m_draw_manager);
		if(!m_sprite_manager ->Initialize("../data/sprites/"))
		{
			return false;
		}
	}

	if (m_level == nullptr)
	{
		m_level = new Level;
		m_level->Load("../data/levels/level.txt",m_sprite_manager, m_manager, m_collmgr, m_input);
	}
	if (m_levelbackground)
	{
		m_levelbackground = new LevelBackground;
		m_levelbackground->Load("../data/levels/levelbackground.txt",m_sprite_manager);
	}



	std::cout << "GameState now running" << std::endl;
	return false;
}

void GameState::Exit()
{

}

bool GameState::Update(float p_deltatime)
{


	m_manager->Update(p_deltatime);
	m_collmgr->CheckCollision();
	HandleInput();



	return true;
}
void GameState::HandleInput()
{
	if (m_input->IsDownOnce(SDLK_k))
	{
		m_engine->m_state_manager.SetState("MenuState");
	}
	if (m_input->IsDownOnce(SDLK_ESCAPE))
	{
		m_engine->m_running = false;
	}


}

void GameState::Draw()
{
	m_draw_manager->Clear();
	m_levelbackground->Draw(m_draw_manager);
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


