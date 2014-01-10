//GlobalGameConfig.cpp
#include "GlobalGameConfig.h"
struct GlobalGameConfigVariables
{
	int musicVolume;
	int soundVolume;
}GlobalGameConfig;

int getMusicVolume(){
		return GlobalGameConfig.musicVolume;
}

int getSoundVolume(){
		return GlobalGameConfig.musicVolume;
}

void setMusicVolume(int vol){
		GlobalGameConfig.musicVolume = vol;
}

void setSoundVolume(int vol){
		GlobalGameConfig.musicVolume = vol;
}