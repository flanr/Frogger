// SpriteManager.h

#pragma once
#include <string>
#include <map>

class Sprite;
class DrawManager;

using namespace std;

class SpriteManager
{
	struct Pair
	{
		struct SDL_Surface *surface;
		struct SDL_Texture *texture;
	};
public:
	SpriteManager(DrawManager *draw_manager);
	~SpriteManager();
	bool Initialize(const string &directory);
	void Cleanup();
	/**
	Returns Sprite from x y of &filename
	**/
	Sprite* Load(const string &filename, int x, int y, int width, int height);

private:
	DrawManager *m_draw_manager;
	string m_directory;
	map<string,Pair> m_sprires;
	

};
