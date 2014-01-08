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
#include "GameObjectManager.h"



Engine::Engine()
{
	m_window=nullptr;
	m_draw_manager=nullptr;
	m_sprite_manager = nullptr;


	m_width = 0;
	m_height = 0;
	m_running = false;
	m_deltatime = 0.01f;
	m_ticks = SDL_GetTicks();
}
Engine::~Engine()
{

}


bool Engine::Initialize()
{
	m_width = 720;
	m_height = 720;

	// Start SDL
	SDL_Init(SDL_INIT_EVERYTHING);
	m_window = SDL_CreateWindow("Flubber",
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

	/*m_sprite_manager = new SpriteManager(m_draw_manager);
	if(!m_sprite_manager->Initialize("../data/sprites/")) {
	return false;
	};*/

	mgr.SetKeyboard(&m_keyboard);
	mgr.SetMouse(&m_mouse);
	menuobjectmanager = new GameObjectManager;
	gameobjectmanager = new GameObjectManager;

	if(mgr.m_current == nullptr)
	{

		mgr.engine = this;
		mgr.Attach(new MenuState(m_draw_manager->GetRenderer(),&m_keyboard,&m_mouse, menuobjectmanager));
		mgr.Attach(new GameState(m_draw_manager->GetRenderer(),&m_keyboard, &m_mouse, gameobjectmanager));


		mgr.SetState("GameState");

	}

	m_running = true;
	return true;
}
void Engine::UpdateDeltatime()
{
	unsigned int ticks = SDL_GetTicks();
	unsigned int delta = ticks - m_ticks;
	m_ticks = ticks;
	m_deltatime = (float)delta * 0.0001f;
	if(m_deltatime > 0.1f) {
		m_deltatime = 0.1f;
	};
}


void Engine::Run()
{

	while(m_running)
	{
		UpdateDeltatime();
		UpdateEvents();

		//if(m_keyboard.IsDownOnce(SDLK_ESCAPE)) {
		//	break;
		//	};


		m_draw_manager->Clear();
		mgr.Update(m_deltatime);
		mgr.Draw();
		m_draw_manager->Present();
		m_keyboard.PostUpdate();
		m_mouse.PostUpdate();

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
		if(event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_k)
			mgr.ChangeState();
		if(event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE)
		{
			m_running = false;
		}
		else if(event.type == SDL_KEYDOWN) {
			int index = event.key.keysym.sym & 0xFF;
			m_keyboard.m_current[index] = true;
		}
		else if(event.type == SDL_KEYUP) {
			int index = event.key.keysym.sym & 0xFF;
			m_keyboard.m_current[index] = false;
		}
		else if(event.type == SDL_MOUSEMOTION) {
			m_mouse.m_x = event.motion.x;
			m_mouse.m_y = event.motion.y;
		}
		else if(event.type == SDL_MOUSEBUTTONDOWN) {
			if(event.button.button == SDL_BUTTON_LEFT) {
				m_mouse.m_current[0] = true;
			}
			else if(event.button.button == SDL_BUTTON_RIGHT) {
				m_mouse.m_current[1] = true;
			};
		}
		else if(event.type == SDL_MOUSEBUTTONUP) {
			if(event.button.button == SDL_BUTTON_LEFT) {
				m_mouse.m_current[0] = false;
			}
			else if(event.button.button == SDL_BUTTON_RIGHT) {
				m_mouse.m_current[1] = false;
			};
		};
	}

};

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
	//if (m_sprite_manager != nullptr)
	//{
	//	m_sprite_manager->Cleanup();
	//	delete m_sprite_manager;
	//	m_sprite_manager=nullptr;
	//}



}

//struct SDL_Window* Engine::GetWindow()
//{
//	return m_window; ///////
//}
//
//int Engine::GetWidth()
//{
//	return m_width;
//}
//
int Engine::GetHeight()
{
	return m_height;
}
