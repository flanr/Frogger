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
#include "MusicClip.h"
#include "MenuState.h"
#include "SoundClip.h"
#include "SoundManager.h"
#include "GameObjectManager.h"
#include "GlobalGameConfig.h"
#include "StartState.h"
#include "constvar.h"


Engine::Engine()
{

	m_window=nullptr;
	m_draw_manager=nullptr;

	m_running = false;

	m_deltatime = 0.01f;
	m_ticks = SDL_GetTicks();

	m_SoundMgr = nullptr;
	m_MusicClip = nullptr;
	m_SoundClip = nullptr;
	Config = new cvarList("Configuration");
	Config->load();

}
Engine::~Engine()
{
	Cleanup();
}


bool Engine::Initialize()
{

	char buffer[1024];
	sprintf(buffer, "%04d", 720);
	//Config->get("VariableName")->getData() returns data in that variable

	if(!Config->get("ResX"))
	{
		Config->set((char*)"ResX",buffer, strlen(buffer));
		Config->save();
	}
	if(!Config->get("ResY"))
	{
		Config->set((char*)"ResY",buffer, strlen(buffer));
		Config->save();
	}
	if(!Config->get("Music Vol")){
		Config->set("Music Vol", "50", strlen("50"));
	}
	setMusicVolume(atoi(Config->get("Music Vol")->getData()));

	// Start SDL

	SDL_Init(SDL_INIT_EVERYTHING);
	if( SDL_Init(SDL_INIT_AUDIO) < 0 ) exit(1);
	m_window = SDL_CreateWindow("Frogger",
		SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,
		GetWidth(),GetHeight(),
		SDL_WINDOW_OPENGL);
	if(m_window == nullptr)
	{
		return false;
	}
	m_draw_manager = new DrawManager;
	if (!m_draw_manager->Initialize(m_window,GetWidth(),GetHeight()))
	{
		return false;
	}

	/*m_sprite_manager = new SpriteManager(m_draw_manager);
	if (!m_sprite_manager->Initialize("../data/sprites/"))
	{
	return false;
	}*/
	if (m_SoundMgr==nullptr)
	{
		m_SoundMgr = new SoundManager();

		m_MusicClip = m_SoundMgr->CreateMusic((std::string)"..\\data\\03.Everyday(Netsky remix).flac");
		m_MusicClip = m_SoundMgr->CreateMusic((std::string)"..\\data\\01StereoLove(Original Mix).flac");
		m_MusicClip = m_SoundMgr->CreateMusic((std::string)"..\\data\\groovin.mp3");
		m_MusicClip = m_SoundMgr->CreateMusic((std::string)"..\\data\\Starchild.mp3");
		m_MusicClip->Play();

	}

	m_state_manager.SetInput(&m_input);

	gameobjectmanager = new GameObjectManager;

	if(m_state_manager.m_current == nullptr)
	{
		m_state_manager.engine = this;
		m_state_manager.Attach(new MenuState(m_draw_manager->GetRenderer(),&m_input, this));
		m_state_manager.Attach(new GameState(m_draw_manager->GetRenderer(),&m_input, gameobjectmanager));
		m_state_manager.Attach(new StartState(m_draw_manager->GetRenderer(),&m_input, gameobjectmanager));

		m_state_manager.SetState("StartState");
	}

	m_running = true;
	return true;
}
void Engine::UpdateDeltatime()
{
	unsigned int ticks = SDL_GetTicks();
	unsigned int delta = ticks - m_ticks;
	m_ticks = ticks;
	m_deltatime = (float)delta * 0.001f;
	if(m_deltatime > 0.1f) {
		m_deltatime = 0.1f;
	};
}

void Engine::Run()
{

	while(m_running)
	{

		if (m_input.IsDownOnce(SDLK_n))
		{
			m_SoundMgr->PlayNext();
		}
		if (m_input.IsDownOnce(SDLK_b))
		{
			m_SoundMgr->PlayPrev();
		}
		m_draw_manager->Clear();
		m_state_manager.Update(m_deltatime);
		m_state_manager.Draw();
		m_draw_manager->Present();
		m_input.PostKeyboardUpdate();
		m_input.PostMouseUpdate();

		m_MusicClip->Volume();
		UpdateDeltatime();
		m_input.HandleInput(&m_running, &m_input, &m_state_manager);
		SDL_Delay(10);
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

	char bacon[1024];
	sprintf(bacon, "%d", getMusicVolume());
	Config->set("Music Vol", bacon, strlen(bacon));
	Config->save();
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
int Engine::GetWidth()
{
	return atoi(Config->get("ResX")->getData());
}

int Engine::GetHeight()
{
	return atoi(Config->get("ResY")->getData());
}
