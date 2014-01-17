// MusicClip.cpp
#include "MusicClip.h"
#include <stdio.h>
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
	printf("Channel: %d - \"%s\"\r\n", m_Channel, Mix_GetError());
	m_Channel = Mix_PlayMusic(m_Clip,0);
	
}
bool MusicClip::IsPlaying()
{
	return Mix_PlayingMusic();	
}

void MusicClip::Pause()
{
	if (m_Channel ==-1)
	{
		return;
	}
	if (Mix_PausedMusic())
	{ 
		Mix_ResumeMusic();
	}else
	{
		Mix_PauseMusic();
	}
}

void MusicClip::Stop()
{
	if (m_Channel == -1)
	{
		return;
	}
	Mix_HaltMusic();
	m_Channel = -1;
	
}

void MusicClip::Volume()
{
	Mix_VolumeMusic(getMusicVolume());
}

