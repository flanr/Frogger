// MusicClip.h
#pragma once
#include <SDL_mixer.h>


class MusicClip
{
public:
	MusicClip();
	~MusicClip();
	MusicClip(Mix_Music* p_Clip);

	void Play();
	void Pause();
	void Stop();
	void Volume();
	bool IsPlaying();
	bool isStopped;

private:
	Mix_Music* m_Clip;
	int m_Channel;
};

