// DrawManager.cpp
#pragma comment (lib,"sdl2.lib")
#pragma comment (lib,"sdl2main.lib")
#include <SDL.h>
#include "DrawManager.h"
#include "Sprite.h"

DrawManager::DrawManager()
{
	m_renderer = nullptr;
}
DrawManager::~DrawManager()
{
}


bool DrawManager::Initialize(struct SDL_Window *window, int width, int height)
{
	m_renderer = SDL_CreateRenderer(window, -1,SDL_RENDERER_ACCELERATED);
	if(m_renderer == nullptr)
	{
		return false;
	}
	return true;
}
void DrawManager::Cleanup()
{
	if(m_renderer != nullptr)
	{
		SDL_DestroyRenderer(m_renderer);
		m_renderer=nullptr;
	}

}
void DrawManager::Clear()
{
	SDL_SetRenderDrawColor(m_renderer, 0x11,0x22,0x33,0xff);
	SDL_RenderClear(m_renderer);
}
void DrawManager::Present()
{
	SDL_RenderPresent(m_renderer);
}
void DrawManager::Draw(Sprite *p_sprite, int p_x, int p_y)
{
	SDL_Rect src = {p_sprite->m_x,p_sprite->m_y,p_sprite->m_width,p_sprite->m_height};
	SDL_Rect dst = {p_x,p_y,p_sprite->m_width,p_sprite->m_height};
	SDL_RenderCopy(m_renderer, p_sprite->m_texture, &src, &dst);
}

SDL_Renderer* DrawManager::GetRenderer()
{
	return m_renderer;
}



