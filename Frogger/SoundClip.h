// SoundClip.h

#pragma once
#include <SDL_mixer.h>


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
