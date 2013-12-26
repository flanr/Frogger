// engine.h

#pragma once
#include "StateManager.h"
class DrawManager;
class SpriteManager;
class Engine{
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
	

private:
	struct SDL_Window *m_window;

	DrawManager *m_draw_manager;
	SpriteManager *m_sprite_manager;
	StateManager mgr;

	bool m_running;
	int m_width;
	int m_height;


};