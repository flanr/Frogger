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
#include "Input.h"
#include "Sprite.h"
#include "GameObject.h"
#include "GameObjectManager.h"

GameState::GameState(SDL_Renderer* renderer, Keyboard *keyboard, Mouse *mouse, GameObjectManager *manager)
{
	this->renderer = renderer;

	m_draw_manager = nullptr;
	m_level = nullptr;
	m_player = nullptr;

	m_keyboard = keyboard;
	m_mouse = mouse;
	m_manager = manager;
	// bool GameStateRunning = false;
}

bool GameState::Enter(Engine* engine)
{
	m_engine = engine;
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
	m_levelbackground = new LevelBackground;
	m_level = new Level;
	m_levelbackground->Load("../data/levels/levelbackground.txt",m_sprite_manager);
	m_level->Load("../data/levels/level.txt",m_sprite_manager);

	Sprite* sprite = m_sprite_manager->Load("hero.png", 0, 0, 70, 70);

	Collider* collider = new Collider(
		m_level->GetPlayerStartPosition(), 
		Vector2(70.0f, 70.0f));

	m_player = new PlayerObject(m_keyboard,sprite, collider);
	m_player->SetPosition(m_level->GetPlayerStartPosition());

	std::cout << "GameState now running" << std::endl;
	return false;
}

void GameState::Exit()
{

}

bool GameState::Update(float p_deltatime)
{

	m_player->Update(p_deltatime);


	return true;
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


