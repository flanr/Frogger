// engine.h

#pragma once
#include "StateManager.h"
#include "InputManager.h"
#include "constvar.h"

class DrawManager;
class SpriteManager;
class SoundManager;
class MusicClip;
class SoundClip;

class GameObjectManager;


class Engine{
	friend class GameState;
public:
	Engine();
	~Engine();
	/**
	Inizializes the Game Window
	**/
	bool Initialize();
	/**
	The Main GameLoop
	Runs every frame
	**/
	void Run();
	/**
	/**
	Gets rid of all the Pointers in a proper way
	**/
	void Cleanup();
	/* struct SDL_Window* GetWindow();*/
	int GetWidth();
	int GetHeight();
	void UpdateDeltatime();

public:
	struct SDL_Window *m_window;

	DrawManager *m_draw_manager;
	SpriteManager *m_sprite_manager;
	StateManager m_state_manager;
	
	
	GameObjectManager *gameobjectmanager;



	cvarList* Config;

	SoundManager *m_SoundMgr;
	MusicClip *m_MusicClip;
	SoundClip *m_SoundClip;


	//Ladbon
	InputManager m_input;


	bool m_running;

	float m_deltatime;
	unsigned int m_ticks;



};