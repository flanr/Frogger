// LevelBackground.h


#pragma once
#include <string>
#include <map>
#include <vector>
#include "Vector2.h"

class SpriteManager;
class DrawManager;
class BackgroundObject;

class LevelBackground
{
	struct Coords
	{
		int x,y,w,h;
	};
public:
	LevelBackground();
	~LevelBackground();

	bool Load(const std::string &p_filename, SpriteManager *p_sprite_manager);
	void Draw(DrawManager *p_draw_manager);

private:
	std::string m_spritemap_filename;
	unsigned int m_width;
	unsigned int m_height;
	std::map<char,Coords> m_tile_coords;

	std::vector<BackgroundObject*> m_objects;
};
