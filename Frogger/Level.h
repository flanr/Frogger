// Level.h


#pragma once
#include <string>
#include <map>
#include <vector>
#include "Vector2.h"

class SpriteManager;
class DrawManager;
class GameObject;
class GameObjectManager;

class Level
{
	struct Coords
	{
		int x,y,w,h;
	};
public:
	Level();
	~Level();

	Vector2 GetStartPosition(GameObject *object);
	bool Load(const std::string &p_filename, SpriteManager *p_sprite_manager);
	void Draw(DrawManager *p_draw_manager);
private:
	std::string m_spritemap_filename;
	unsigned int m_width;
	unsigned int m_height;
	std::map<char,Coords> m_tile_coords;



	GameObjectManager* gom;
	Vector2 m_start_position;

};

