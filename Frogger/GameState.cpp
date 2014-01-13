// GameState.cpp

#include "GameState.h"
#include <iostream>
#include "Level.h"
#include "LevelBackground.h"
#include "DrawManager.h"
#include "SpriteManager.h"
#include "Engine.h"
#include "PlayerObject.h"
#include "Collider.h"
#include "InputManager.h"
#include "Sprite.h"
#include "GameObject.h"
#include "GameObjectManager.h"
#include "Water.h"
#include "CollisionManager.h"
#include "Sprite.h"
#include "Collider.h"


GameState::GameState(SDL_Renderer* renderer, InputManager *input, GameObjectManager *manager)
{
	this->renderer = renderer;
	m_draw_manager = nullptr;
	m_level = nullptr;
	m_player = nullptr;
	m_water = nullptr;
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
	// GameStateRunning = true:
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
		m_level->Load("../data/levels/level.txt",m_sprite_manager);
	}
	if (m_levelbackground)
	{
		m_levelbackground = new LevelBackground;
		m_levelbackground->Load("../data/levels/levelbackground.txt",m_sprite_manager);
	}


	if (m_sprite == nullptr)
	{
		m_sprite = m_sprite_manager->Load("hero.png", 0, 0, 70, 70);
	}

	if(m_collider == nullptr)
	{
		m_collider = new Collider(
			m_level->GetStartPosition(m_player), 
			Vector2(70.0f, 70.0f));
	}
	if (m_collmgr ==nullptr)
	{
		m_collmgr = new CollisionManager;
	}


	if (m_player == nullptr)
	{
		m_player = new PlayerObject(m_input, m_sprite, m_collmgr->CreateCollider(m_level->GetStartPosition(m_player), Vector2(70.0f, 70.0f)));
		m_player->SetPosition(m_level->GetStartPosition(m_player));
	}

	if (m_water == nullptr)
	{
		m_water = new Water(nullptr, m_collmgr->CreateCollider(m_level->GetStartPosition(m_water), Vector2(70.0f, 70.0f)));
		m_water->SetPosition(m_level->GetStartPosition(m_water));
	}
	std::cout << "GameState now running" << std::endl;
	return false;
}

void GameState::Exit()
{

}

bool GameState::Update(float p_deltatime)
{
	m_player->Update(p_deltatime);
	m_water->Update(p_deltatime);

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

	m_draw_manager->Draw(
		m_player->GetSprite(),
		m_player->GetPosition().m_x,
		m_player->GetPosition().m_y);
	m_draw_manager->Present();
}


std::string GameState::Next()
{
	return "MenuState";
}

bool GameState::IsType(const std::string &p_type)
{
	return p_type.compare("GameState") == 0;
}


