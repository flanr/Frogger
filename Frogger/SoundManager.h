// SoundManager.h


#pragma once

#include <string>
#include <map>
#include <vector>
#include <SDL_mixer.h>


class MusicClip;
class SoundClip;

class SoundManager
{
public:
	SoundManager();
	~SoundManager();
	MusicClip* CreateMusic(std::string p_Path);
	SoundClip* CreateSound(std::string p_Path);
	void PlayNext();
	void PlayPrev();
	MusicClip* GetMusicClip();
private:
	int m_current;
	std::map<std::string, Mix_Music*> m_Music;
	std::map<std::string, Mix_Chunk*> m_Sounds;
	std::vector<MusicClip*> m_MusicClips;
	std::vector<SoundClip*> m_SoundClips;
};
// Mix_ChannelFinished