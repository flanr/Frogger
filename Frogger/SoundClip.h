// SoundClip.h

#pragma once
#include <SDL_mixer.h>
#ifndef SOUNDCLIP_H_INCLUDED
#define SOUNDCLIP_H_INCLUDED

class SoundClip
{
public:
	SoundClip();
	~SoundClip();
	SoundClip(Mix_Chunk* p_Clip);

	void Play();
	void Pause();
	void Stop();

private:
	Mix_Chunk* m_Clip;
	int m_Channel;
};

#endif