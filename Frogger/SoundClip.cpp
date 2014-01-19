// SoundClip.cpp

#include "SoundClip.h"
#include "GlobalGameConfig.h"

SoundClip::SoundClip()
{
	m_Clip = nullptr;
	m_Channel = -1;
}

SoundClip::~SoundClip()
{
	m_Clip = nullptr;
	m_Channel = -1;
}

SoundClip::SoundClip(Mix_Chunk* p_Clip)
{
	m_Clip = p_Clip;
	m_Channel = -1;
}

void SoundClip::Play()
{
	m_Channel = Mix_PlayChannel(-1,m_Clip,0);
}

void SoundClip::Pause()
{
	if(m_Channel == -1)
	{
		return;
	}
	if (Mix_Paused(m_Channel))
	{
		Mix_Resume(m_Channel);
	}
	else
	{
		Mix_Pause(m_Channel);
	}
}

void SoundClip::Stop()
{
	if (m_Channel == -1)
	{
		return;
	}
	Mix_HaltChannel(m_Channel);
	m_Channel = -1;
}

