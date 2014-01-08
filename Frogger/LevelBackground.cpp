// LevelBackground.cpp

#include "LevelBackground.h"
#include <sstream>
#include <fstream>
#include "Sprite.h"
#include "SpriteManager.h"
#include "DrawManager.h"
#include "BackgroundObject.h"


LevelBackground::LevelBackground()
{
	m_height = 0;
	m_width =0;
}

LevelBackground::~LevelBackground()
{
	auto it = m_objects.begin();
	while (it != m_objects.end())
	{
		delete (*it)->GetSprite();
		delete (*it);
		it++;
	}

}


bool LevelBackground::Load(const std::string &p_filename, SpriteManager *p_sprite_manager)
{
	ifstream stream(p_filename);
	if(!stream.is_open())
	{
		return false;
	}
	string row;
	unsigned int coord_count =0;
	stream >> m_spritemap_filename;
	stream >> coord_count >> m_width >> m_height;
	getline(stream,row);
	for (unsigned int i=0; i<coord_count;i++)
	{
		getline(stream,row);
		stringstream ss(row);
		string ch;
		Coords coord;

		ss>>ch;
		ss>>coord.x;
		ss>>coord.y;
		ss>>coord.w;
		ss>>coord.h;

		m_tile_coords.insert(pair<char,Coords>(ch[0],coord));
	}
	unsigned int x = 0;
	unsigned int y = 0;

	while (!stream.eof())
	{
		getline(stream, row, '\n');
		if(row.length()==0)
		{
			continue;
		}
		
		for (unsigned int i=0; i<row.length();i++)
		{
			if(row[i]=='0')
			{
				x+=m_width;
				continue;
			}
			map<char,Coords>::iterator it = m_tile_coords.find(row[i]);
			if (it == m_tile_coords.end())
			{
				continue;
			}
			Coords &c = it->second;
			Sprite *sprite = p_sprite_manager->Load(m_spritemap_filename,c.x,c.y,c.w,c.h);

			BackgroundObject *bo = new BackgroundObject(sprite);
			bo->SetPosition(Vector2(x,y));
			m_objects.push_back(bo); // vad är detta ? 

			x += m_width;

		}
		y += m_height;
		x=0;
	}
	stream.close();
	return true;

}

void LevelBackground::Draw(DrawManager *p_draw_manager)
{
	for (auto i=0UL; i< m_objects.size(); i++)
	{
		p_draw_manager->Draw(m_objects[i]->GetSprite(),
			m_objects[i]->GetPosition().m_x,
			m_objects[i]->GetPosition().m_y);
	}

}
