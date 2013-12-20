// Engine.cpp
#include "Engine.h"
#include <SDL.h>
#pragma comment (lib,"sdl2.lib")
#pragma comment (lib,"sdl2main.lib")
#include "DrawManager.h"
#include "StateManager.h"
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

	if(mgr.m_current == nullptr)
	{
		mgr.Attach(new MenuState);
		mgr.Attach(new GameState);
		mgr.SetState("MenuState");
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


}
