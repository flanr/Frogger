// Level.cpp
#include "Level.h"
#include <sstream>
#include <fstream>
#include "Sprite.h"
#include "SpriteManager.h"
#include "DrawManager.h"
#include "GameObject.h"
#include "Collider.h"

Level::Level()
{
	m_height =0;
	m_width =0;
}

bool Level::Load(const std::string &p_filename, SpriteManager *p_sprite_manager)
{
	std::ifstream stream(p_filename);
	if(!stream.is_open())
	{
		return false;
	}
	std::string row;
	unsigned int coord_count=0;
	stream >> m_spritemap_filename;
	stream >> coord_count >> m_width >> m_height;
	std::getline(stream,row);
	for(unsigned int i=0;i<coord_count;i++)
	{
		std::getline(stream,row);
		std::stringstream ss(row);
		std::string ch;
		Coords coord;

		ss >> ch;
		ss >> coord.x;
		ss >> coord.y;
		ss >> coord.w;
		ss >> coord.h;

		m_tile_coords.insert( std::pair<char,Coords>(ch[0],coord));
	}
	unsigned int x = 0;
	unsigned int y = 0;

	while (!stream.eof())
	{
		std::getline(stream, row, '\n');
		if(row.length()==0)
		{
			continue;
		}
		x=0;
		for (unsigned int i=0;i<row.length();i++)
		{
			if(row[i]=='0')
			{
				x +=m_width;
				continue;
			}else if(row[i] == 'S')
			{
				m_start_position.m_x = x;
				m_start_position.m_y = y;
				x += m_width;
				continue;
			}
			std::map<char,Coords>::iterator it = m_tile_coords.find(row[i]);
			if(it == m_tile_coords.end())
			{
				continue;
			}
			Coords &c = it->second;
			Sprite *sprite = p_sprite_manager->Load(m_spritemap_filename,c.x,c.y,c.w,c.h);

			// COLLIDER
			Collider *collider = new Collider;
			collider->m_position = Vector2(x,y);
			collider->m_extension = Vector2(c.w,c.h);

			GameObject *go = new GameObject(sprite, collider);
			go->SetPosition(Vector2(x,y));
			m_objects.push_back(go);



			x += m_width;

		}
		y += m_height;
	}
	stream.close();
	return true;

}


Level::~Level()
{
	auto it = m_objects.begin();
	while(it !=m_objects.end())
	{
		delete (*it)->GetSprite();
		delete (*it)->GetCollider();
		delete (*it);
		it++;
	}


}

void Level::Draw(DrawManager *p_draw_manager)
{
for(auto i=0UL; i < m_objects.size();i++)
	{
		p_draw_manager->Draw(m_objects[i]->GetSprite(),
			m_objects[i]->GetPosition().m_x,
			m_objects[i]->GetPosition().m_y);
	}
}

Vector2 Level::GetPlayerStartPosition()
{
	return m_start_position;
}
