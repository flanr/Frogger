//GameObjectManager.cpp

#include "GameObjectManager.h"
#include "GameObject.h"
#include "DrawManager.h"

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
	}
}
//attach 
void GameObjectManager::AttachObject(GameObject *object)
{
	m_gameobject.push_back(object);
}
//detach
void GameObjectManager::DetachObject(GameObject *object)
{
	for (auto it = m_gameobject.begin(); it != m_gameobject.end(); ++it)
	{
		if (*it == object)
		{
			delete *it;
			*it = nullptr;
			m_gameobject.erase(it);
		}
	}
}
//draw
void GameObjectManager::DrawObject(DrawManager *draw)
{
	for (auto it = m_gameobject.begin(); it != m_gameobject.end(); ++it)
	{
		GameObject *obj = *it;
		if (obj->HasSprite())
		{
			draw->Draw(obj->GetSprite(), obj->GetPosition().m_x, obj->GetPosition().m_y);
		}
	}
}