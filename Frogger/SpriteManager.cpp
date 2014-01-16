// SpriteManager.cpp

#include <SDL_image.h>
#pragma comment(lib,"sdl2_image.lib")

#include "SpriteManager.h"
#include "Sprite.h"
#include "DrawManager.h"

#include "Animation.h"
#include <string>

#include <fstream>
#include <sstream>

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
	map<string,Pair>::iterator it = m_sprires.begin();
	while(it != m_sprires.end())
	{
		SDL_FreeSurface(it->second.surface);
		SDL_DestroyTexture(it->second.texture);
		it++;
	}
	m_sprires.clear();
	IMG_Quit();

}


Sprite* SpriteManager::Load(const string &p_filename, int p_x, int p_y, int p_width, int p_height)
{
	map<string,Pair>::iterator it = m_sprires.find(p_filename); // Iterator checks all elements
	if(it == m_sprires.end())
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

		m_sprires.insert(std::pair<string,Pair>(p_filename,pair));
		it = m_sprires.find(p_filename);
	}
	return new Sprite(it->second.surface,it->second.texture,p_x,p_y,p_width,p_height);
}
Animation *SpriteManager::Load(const std::string &p_filename)
{
		std::fstream stream;
	stream.open(p_filename.c_str());
	if(!stream.is_open())
	{
		return nullptr;
	}

std::string row;
	stream >> row;
	std::map<std::string,Pair>::iterator it = m_sprires.find(row);
	if(it == m_sprires.end())
	{
			if(!LoadImage(row))
			{
				stream.close();
				return nullptr;
			}
			it = m_sprires.find(row);
    }

SDL_Surface *surface = it->second.surface;
SDL_Texture *texture = it->second.texture;
Animation *sprite = new Animation(surface, texture, 0, 0, 0, 0);

while(!stream.eof())
{
std::getline(stream, row);
	if(row.length() == 0) 
	{
		continue; 
	}

	std::stringstream ss(row);

	Animation::Frame frame;
	ss >> frame.duration;
	ss >> frame.x;
	ss >> frame.y;
	ss >> frame.w;
	ss >> frame.h;
	
	sprite->AddFrame(frame);

}

	stream.close();
	return sprite;
}

bool SpriteManager::LoadImage(const std::string &p_filename)
{
	std::string path = m_directory + p_filename;
	SDL_Surface *surface = IMG_Load(path.c_str());
	const char *error = IMG_GetError();
	if(surface == nullptr)
	{
		return false;
	}

	SDL_Texture *texture = SDL_CreateTextureFromSurface(
		m_draw_manager->m_renderer,
		surface);

	Pair pair = {surface, texture };
	m_sprires.insert( std::pair<std::string, Pair>(p_filename, pair));

	return true;
}