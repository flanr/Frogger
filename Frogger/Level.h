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
class CollisionManager;
class InputManager;
class Water;
class PlayerObject;
class Sprite;

class Level
{
	struct Coords
	{
		int x,y,w,h;
	};
public:
	Level();
	~Level();

	Vector2 GetStartPosition();
	bool Load(const std::string &p_filename, SpriteManager *p_sprite_manager
		, GameObjectManager *m_manager
		, CollisionManager *collmgr,
		InputManager *input);

	void Draw(DrawManager *p_draw_manager);

private:

	std::string m_spritemap_filename;
	unsigned int m_width;
	unsigned int m_height;
	std::map<char,Coords> m_tile_coords;


	CollisionManager *m_collmgr;
	GameObjectManager *gom;
	Vector2 m_start_position;

	PlayerObject* m_player;
	Water *m_water;
	Sprite *m_sprite;
};

