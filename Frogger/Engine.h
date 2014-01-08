// engine.h

#pragma once
#include "StateManager.h"
#include "Input.h"

class DrawManager;
class SpriteManager;

class DrawManager;
class SpriteManager;
<<<<<<< HEAD
class SoundManager;
class MusicClip;
class SoundClip;
=======

class GameObjectManager;

>>>>>>> 948122011e19de45636c17dd9888beba34d8b268
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
	Updating Input?
	**/
	void UpdateEvents();
	/**
	Gets rid of all the Pointers in a proper way
	**/
	void Cleanup();
	/* struct SDL_Window* GetWindow();
	int GetWidth();*/
	int GetHeight();

	//UpdateDeltatime for player?
	void UpdateDeltatime();

public:
	struct SDL_Window *m_window;
	int m_width;
	int m_height;
	DrawManager *m_draw_manager;
	SpriteManager *m_sprite_manager;
	StateManager mgr;
	GameObjectManager *menuobjectmanager;
	GameObjectManager *gameobjectmanager;



	Keyboard m_keyboard;// dessa måste ändras till "include InputManager men tills vidare
	Mouse m_mouse; // samma här

	float m_deltatime;
	unsigned int m_ticks;

	SoundManager *m_SoundMgr;
	MusicClip *m_MusicClip;
	SoundClip *m_SoundClip;

	bool m_running;



};