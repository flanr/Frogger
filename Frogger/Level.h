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
class Car;
class Tree;
class Goal;

class Level
{
	struct Coords
	{
		int x,y,w,h;
	};
public:
	Level();
	~Level();

	bool Load(const std::string &p_filename, SpriteManager *p_sprite_manager
		, GameObjectManager *m_manager
		, CollisionManager *collmgr,
		InputManager *input);

	void Draw(DrawManager *p_draw_manager);

protected:

	std::string m_spritemap_filename;
	unsigned int m_width;
	unsigned int m_height;
	std::map<char,Coords> m_tile_coords;


	CollisionManager *m_collmgr;
	GameObjectManager *gom;

	Vector2 m_player_start_position;
	Vector2 m_water_start_position;
	Vector2 m_car_start_position;
	Vector2 m_tree_start_position;
	Vector2 m_goal_start_position;

	Goal *m_goal;
	Tree *m_tree;
	Car *m_car;
	PlayerObject* m_player;
	Water *m_water;
	Sprite *m_sprite;
};

