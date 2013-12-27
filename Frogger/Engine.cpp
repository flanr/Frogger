// Engine.cpp
#include "Engine.h"
#include <SDL.h>
#include <thread>

#pragma comment (lib,"sdl2.lib")
#pragma comment (lib,"sdl2main.lib")
#include "DrawManager.h"
#include "StateManager.h"
#include "SpriteManager.h"
#include "GameState.h"
#include "MenuState.h"


Engine::Engine()
{
	m_window=nullptr;
	m_draw_manager=nullptr;

	m_width = 0;
	m_height = 0;
	m_running = false;
}
Engine::~Engine()
{

}


bool Engine::Initialize()
{
	m_width = 1024;
	m_height = 640;

	// Start SDL
	SDL_Init(SDL_INIT_EVERYTHING);
	m_window = SDL_CreateWindow("Frogger",
		SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,
		m_width,m_height,
		SDL_WINDOW_OPENGL);
	if(m_window == nullptr)
	{
		return false;
	}
	m_draw_manager = new DrawManager;
	if (!m_draw_manager->Initialize(m_window,m_width,m_height))
	{
		return false;
	}

	m_sprite_manager = new SpriteManager(m_draw_manager);
	if (!m_sprite_manager->Initialize("../data/sprites/"))
	{
		return false;
	}


	if(mgr.m_current == nullptr)
	{
		mgr.Attach(new MenuState(m_draw_manager->GetRenderer()));
		mgr.Attach(new GameState(m_draw_manager->GetRenderer()));
		mgr.SetState("GameState");
	}
	
m_running = true;
	return true;
}

void Engine::Run()
{

	while(m_running)
	{
		UpdateEvents();
		
		m_draw_manager->Clear();
		mgr.Update(10);
		mgr.Draw();
		m_draw_manager->Present();

		SDL_Delay(10);
	}



}

void Engine::UpdateEvents()
{
	SDL_Event event;
	while(SDL_PollEvent(&event))
	{
		if(event.type == SDL_QUIT)
		{
			m_running=false;
		}
		if(event.type == SDL_KEYDOWN && event.key.keysym.sym == 'k')
			mgr.ChangeState();

	}

}


void Engine::Cleanup()
{
	if (m_window !=nullptr)
	{
		SDL_DestroyWindow(m_window);
		m_window = nullptr;
	}
	if (m_draw_manager !=nullptr)
	{
		m_draw_manager->Cleanup();
		delete m_draw_manager;
		m_draw_manager=nullptr;
	}
	if (m_sprite_manager != nullptr)
	{
		m_sprite_manager->Cleanup();
		delete m_sprite_manager;
		m_sprite_manager=nullptr;
	}


}
