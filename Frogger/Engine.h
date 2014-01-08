// engine.h

#pragma once
#include "StateManager.h"
class DrawManager;
class SpriteManager;
class SoundManager;
class MusicClip;
class SoundClip;
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

public:
	struct SDL_Window *m_window;
	int m_width;
	int m_height;
	DrawManager *m_draw_manager;
	SpriteManager *m_sprite_manager;
	StateManager mgr;

	SoundManager *m_SoundMgr;
	MusicClip *m_MusicClip;
	SoundClip *m_SoundClip;

	bool m_running;



};