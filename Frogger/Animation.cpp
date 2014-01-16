//Animation.cpp


#include "Animation.h"

Animation::Animation(SDL_Surface *surface, SDL_Texture *texture,
					 int x, int y, int width, int height)
					 :Sprite(surface, texture, x, y, width, height)
{
	m_current_frame = 0;
	m_time = 0.0f;
}

void Animation::Update(float deltatime)
{
	m_time +=deltatime;
	if(m_time >= m_animation[m_current_frame].duration)	
	{
		m_time = 0.0f;
		m_current_frame = ++m_current_frame % m_animation.size();

		Frame &frame = m_animation[m_current_frame];
		m_x = frame.x;
		m_y = frame.y;
		m_width = frame.w;
		m_height =frame.h;
	}
}

void Animation::AddFrame(Frame &frame)
{
	m_animation.push_back(frame);
}
