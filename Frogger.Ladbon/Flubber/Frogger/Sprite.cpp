// Sprite.cpp
#include "Sprite.h"
#include <SDL.h>
#pragma comment(lib,"sdl2.lib")

Sprite::Sprite(SDL_Surface *p_surface, SDL_Texture *p_texture, int p_x, int p_y, int p_width, int p_height)
{
	m_surface = p_surface;
	m_texture = p_texture;
	m_x = p_x;
	m_y = p_y;
	m_width = p_width;
	m_height = p_height;
}
