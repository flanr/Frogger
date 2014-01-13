// Soundmanager.cpp

#include "SoundManager.h"
#include <SDL_mixer.h>
#pragma comment (lib,"SDL2_mixer.lib")
#include "SoundClip.h"
#include "MusicClip.h"

SoundManager::SoundManager()
{
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT,2,2048)<0)
	{
		printf("SDL_Mixer :: Mix_OpenAudio %s\n", Mix_GetError());
	}
	m_current = 1;
}

SoundManager::~SoundManager()
{
	for (unsigned int i = 0; i < m_SoundClips.size(); i++)
	{
		delete m_SoundClips[i];
		m_SoundClips[i] = nullptr;
	}
	m_SoundClips.clear();

	for (unsigned int i = 0; i < m_MusicClips.size(); i++)
	{
		delete m_MusicClips[i];
		m_MusicClips[i] = nullptr;
	}
	m_MusicClips.clear();
	{
		std::map<std::string, Mix_Chunk*>::iterator It = m_Sounds.begin();
		while (It != m_Sounds.end())
		{
			Mix_FreeChunk(It->second);
			It->second = nullptr;
			It++;
		}
		m_Sounds.clear();
	}
	{
		std::map<std::string, Mix_Music*>::iterator It = m_Music.begin();
		while (It != m_Music.end())
		{
			Mix_FreeMusic(It->second);
			It->second = nullptr;
			It++;
		}
		m_Music.clear();
	}
}


SoundClip* SoundManager::CreateSound(std::string p_Path)
{
	SoundClip* Return = nullptr;
	std::map<std::string,Mix_Chunk*>::iterator It = m_Sounds.find(p_Path);
	if (It == m_Sounds.end())
	{
		Mix_Chunk* Sound = Mix_LoadWAV(p_Path.c_str());
		std::pair<std::string,Mix_Chunk*> Pair;
		Pair = std::make_pair(p_Path,Sound);
		m_Sounds.insert(Pair);
		Return = new SoundClip(Sound);
	}
	else
	{
		Return = new SoundClip(It->second);
	}
	m_SoundClips.push_back(Return);

	return Return;
}

MusicClip* SoundManager::CreateMusic(std::string p_Path)
{
	MusicClip* Return = nullptr;
	std::map<std::string, Mix_Music*>::iterator It = m_Music.find(p_Path);
	if (It == m_Music.end())
	{
		const char* szPath = p_Path.c_str();
		Mix_Music* Music;
		try{
			printf("Mix_LoadMUS(\"%s\");\r\n", szPath);
			Music = Mix_LoadMUS((char*)szPath);
		}catch(...){
			printf("Error!\r\nFire! Fire! Hope to hear from you soon.");
		}
		std::pair<std::string,Mix_Music*> Pair;
		Pair = std::make_pair(p_Path,Music);
		m_Music.insert(Pair);
		Return = new MusicClip(Music);
	}
	else
	{
		Return = new MusicClip(It->second);
	}
	m_MusicClips.push_back(Return);
	return Return;
}
void SoundManager::PlayNext()
{
	m_MusicClips[m_current]->Stop();
	m_current = (m_current + 1) % m_MusicClips.size();
	m_MusicClips[m_current]->Play();


}
MusicClip* SoundManager::GetMusicClip()
{
	return m_MusicClips[m_current];    
}
