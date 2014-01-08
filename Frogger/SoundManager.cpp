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
		Mix_Music* Music = Mix_LoadMUS(p_Path.c_str());
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
