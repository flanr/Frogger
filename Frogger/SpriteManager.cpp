// SpriteManager.cpp

#include <SDL_image.h>
#pragma comment(lib,"sdl2_image.lib")

#include "SpriteManager.h"
#include "Sprite.h"
#include "DrawManager.h"

SpriteManager::SpriteManager(DrawManager *p_draw_manager)
{
	m_draw_manager = p_draw_manager;
}

SpriteManager::~SpriteManager()
{

}

bool SpriteManager::Initialize(const string &p_directory)
{
	IMG_Init(IMG_INIT_PNG);
	m_directory = p_directory;
	return true;
}

void SpriteManager::Cleanup()
{
	map<string,Pair>::iterator it = m_sprites.begin();
	while(it != m_sprites.end())
	{
		SDL_FreeSurface(it->second.surface);
		SDL_DestroyTexture(it->second.texture);
		it++;
	}
	m_sprites.clear();
	IMG_Quit();

}


Sprite* SpriteManager::Load(const string &p_filename, int p_x, int p_y, int p_width, int p_height)
{
	map<string,Pair>::iterator it = m_sprites.find(p_filename); // Iterator checks all elements
	if(it == m_sprites.end())
	{

		string path = m_directory + p_filename; 
		SDL_Surface* surface = IMG_Load(path.c_str());
		if(surface == nullptr)
		{
			return nullptr;
		}
		SDL_Texture* texture = SDL_CreateTextureFromSurface(
			m_draw_manager->m_renderer,
			surface);

		Pair pair = {surface, texture};

		m_sprites.insert(std::pair<string,Pair>(p_filename,pair));
		it = m_sprites.find(p_filename);
	}
	return new Sprite(it->second.surface,it->second.texture,p_x,p_y,p_width,p_height);
}
