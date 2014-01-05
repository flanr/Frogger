// MusicClip.h
#pragma once
#include <SDL_mixer.h>
#ifndef MUSICCLIP_H_INCLUDED
#define MUSICCLIP_H_INCLUDED

class MusicClip
{
public:
	MusicClip();
	~MusicClip();
	MusicClip(Mix_Music* p_Clip);

	void Play();
	void Pause();
	void Stop();

private:
	Mix_Music* m_Clip;
	int m_Channel;
};


#endif