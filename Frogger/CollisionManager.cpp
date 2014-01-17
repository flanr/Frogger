//CollisionManager.cpp

#include "CollisionManager.h"
#include "Vector2.h"
#include "GameState.h"
#include "Collider.h"
#include "GameObject.h"
#include "GameObjectManager.h"
#include <iostream>
#include "level.h"
#include <vector>

CollisionManager::CollisionManager()
{
	//amount_of_objects = 0;
}


CollisionManager::~CollisionManager()
{

}
void CollisionManager::CheckCollision()
{
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// S� MINA COLLIDERS SKA J�MF�RAS MED VARANDRA OCH SE OM DE COLLIDERAR, OM DET SKAPAS ETT OFFSET V�RDE M�STE DE SKICKAS TILL DIN PARENT(GAMEOBJECT)///
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	Vector2 wall_collision(720.0f, 720.0f);
	Vector2 offset(0.0, 0.0);
	int count = 0;
	for(auto i = 0UL; i < m_object.size()-1; i++) {
		for(int z = i+1; z < m_object.size(); z++)
		{

			Vector2 off(0.0, 0.0);

			if(m_object.at(z)->m_xobject->GetType() == PLAYER)
			{
				if(m_object.at(z)->m_position.m_x > 720 || m_object.at(z)->m_position.m_y > 720 
					|| m_object.at(z)->m_position.m_x < 0 || m_object.at(z)->m_position.m_y < 0)
				{
					m_object.at(z)->NotifyParent(m_object.at(z)->m_xobject);
				}
			}
			////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			//               object[0] h�mtar collider objektet fr�n gameobjectet(collider)                                   //////
			//och kollar om den �verlappar med ett annat gameobject i samma lista(som den h�mtar collider fr�n dess parameter)//////
			////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			if(m_object.at(i)->Overlap(*m_object.at(z), off)) 
			{ 
				offset += off;
				count++;

				////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
				//JAG VILL SKICKA COLLIDERNA SOM KOLLIDERADE MED VARANDRA TILL SIN RESPEKTIVE GAMEOBJECT SOM HAR COLLIDERNA SOM PARAMETER///
				////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
				//std::cout << "CheckCollision(): " <<  m_object.at(i) << " och andra objektet: " << m_object.at(z) << "\n";
				//std::cout << "  " <<  m_object.at(i)->m_xobject << " || " << m_object.at(z)->m_xobject << "\n";

				if(m_object.at(z)->m_xobject->GetType() == PLAYER)
				{
					if(off.m_x < 1.0 || off.m_x > 1.0 || off.m_y > 1.0 ||off.m_y < 1.0 )
					{
						//TREE COLLISION
						if(m_object.at(i)->m_xobject->GetType() == LOG )
						{

							m_object.at(z)->m_xobject->m_is_on_log = true;
							m_object.at(z)->m_xobject->SetPosition(m_object.at(i)->m_xobject->GetPosition());
							return;

						}else// if(m_object.at(i)->m_xobject->GetType() == WATER && !m_object.at(z)->m_xobject->m_is_on_log)
						{
							m_object.at(z)->m_xobject->m_is_on_log = false;
						}
						if(m_object.at(z)->m_xobject->m_is_on_log = true && m_object.at(i)->m_xobject->GetType() == GOAL)
						{
							m_object.at(z)->NotifyParent(m_object.at(z)->m_xobject);
							//m_object.at(i) DETTA �R COLLIDER TILL M�LET DU TR�FFAR
							//m_object.at(i)->m_xobject 
							std::cout << " DU TRAEFFADE MOELET\n";
						}
						//WATER AND CAR COLLISION
						if((m_object.at(i)->m_xobject->GetType() == WATER && m_object.at(z)->m_xobject->m_is_on_log == false)
							|| m_object.at(i)->m_xobject->GetType() == CAR)
						{
							m_object.at(z)->NotifyParent(m_object.at(z)->m_xobject);
						}
						//				m_object.at(z)->NotifyParent(m_object.at(i)->m_xobject);

						printf("%2d %f %f\n", count, offset.m_x, offset.m_y);
					}
				}
			};
		};
	};
	if(count > 0) {
		offset /= (float)count;
		offset.m_x=floorf(offset.m_x);
		offset.m_y=floorf(offset.m_y);

	};
}
Collider *CollisionManager::CreateCollider(Vector2 &position, Vector2 &extension)
{

	Collider *collider = new Collider(position, extension);
	//	m_object.at(amount_of_objects).push_back(collider);
	m_object.push_back(collider);
	//	std::cout << "Collider: " << collider << "\n";
	//amount_of_objects++;
	return collider;

}
void CollisionManager::DestroyCollider(Collider *collider)
{
	for (auto it = m_object.begin(); it != m_object.end(); ++it)
	{
		if (*it == collider)
		{
			delete *it;
			*it = nullptr;
			m_object.erase(it);
			break;
		}
	}
}
