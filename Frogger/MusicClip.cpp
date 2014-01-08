// MusicClip.cpp
#include "MusicClip.h"
#include "GlobalGameConfig.h"

MusicClip::MusicClip()
{
	m_Clip = nullptr;
	m_Channel = -1;
}

MusicClip::~MusicClip()
{
	m_Clip = nullptr;
	m_Channel = -1;
}

MusicClip::MusicClip(Mix_Music* p_Clip)
{
	m_Clip = p_Clip;
	m_Channel = -1;
}

void MusicClip::Play()
{
	m_Channel = Mix_PlayMusic(m_Clip, -1);
}

void MusicClip::Pause()
{
	if (m_Channel ==-1)
	{
		return;
	}
	if (Mix_Paused(m_Channel))
	{
		Mix_Resume(m_Channel);
	}else
	{
		Mix_Pause(m_Channel);
	}
}

void MusicClip::Stop()
{
	if (m_Channel == -1)
	{
		return;
	}
	Mix_HaltChannel(m_Channel);
	m_Channel = -1;
}

void MusicClip::Volume()
{
	Mix_Volume(-1,GlobalGameConfig.musicVolume);
}
