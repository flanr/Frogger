//GameObjectManager.cpp

#include "GameObjectManager.h"
#include "GameObject.h"
#include "DrawManager.h"
#include "Collider.h"
#include "Sprite.h"
#include <iostream>

GameObjectManager::GameObjectManager()
{

}
GameObjectManager::~GameObjectManager()
{

}
//Update
void GameObjectManager::Update(float deltatime)
{
	for (auto it = m_gameobject.begin(); it != m_gameobject.end(); ++it)
	{
		GameObject *obj = *it;
		obj->Update(deltatime);
		if(obj->GetType() == PLAYER)
		{
			obj->GetSprite()->Update(deltatime);
		}
	}
}
//GetStartPosition
Vector2 GameObjectManager::GetStartPosition(GameObject *GO)
{
	return GO->GetStartPosition();
}
//attach 
void GameObjectManager::AttachObject(GameObject *object)
{

	m_gameobject.push_back(object);

}
//detach
void GameObjectManager::DetachObject(GameObject *object)
{
	for (unsigned int i=0; i<m_gameobject.size(); i++)
	{
		if (m_gameobject[i] == object)
		{
			delete m_gameobject[i];
			m_gameobject[i] = nullptr;
			m_gameobject.erase(m_gameobject.begin()+i);
		}
	}
}
void GameObjectManager::DetachObject()
{
	for( auto it = m_gameobject.begin();it != m_gameobject.end(); it++) 
	{			
		delete (*it)->GetCollider();
		delete *it;
		*it = nullptr;
		m_gameobject.erase(it);


	}

}

void GameObjectManager::DrawObject(DrawManager *draw)
{
	for (auto it = m_gameobject.begin(); it != m_gameobject.end(); ++it)
	{
		GameObject *obj = *it;
		if (obj->HasSprite())
		{
			if(obj->GetType() == PLAYER)
			{
				draw->Draw(obj->GetSprite(), obj->GetPosition().m_x, obj->GetPosition().m_y, 70, 70);
			}
			else
			{
				draw->Draw(obj->GetSprite(), obj->GetPosition().m_x, obj->GetPosition().m_y);
			}
		}
	}
}