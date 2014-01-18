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

CollisionManager::CollisionManager(GameObjectManager *gom)
{
	m_gom = gom;
	score = 0;
}


CollisionManager::~CollisionManager()
{

}
void CollisionManager::CheckCollision()
{
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// SÅ MINA COLLIDERS SKA JÄMFÖRAS MED VARANDRA OCH SE OM DE COLLIDERAR, OM DET SKAPAS ETT OFFSET VÄRDE MÅSTE DE SKICKAS TILL DIN PARENT(GAMEOBJECT)///
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	Vector2 wall_collision(720.0f, 720.0f);
	Vector2 offset(0.0, 0.0);
	int count = 0;
	int instance = 0;

	for(auto i = 0UL; i < m_object.size()-1; i++) {
		for(auto z = i+1; z < m_object.size(); z++)
		{
			Vector2 off(0.0, 0.0);
			
			if(m_object.at(z)->m_xobject->GetType() == PLAYER) // WALL "COLLISION"
			{
				instance = z;
				if(m_object.at(z)->m_position.m_x > 720 || m_object.at(z)->m_position.m_y > 720 
					|| m_object.at(z)->m_position.m_x < 0 || m_object.at(z)->m_position.m_y < 0)
				{
					m_object.at(z)->NotifyParent(m_object.at(z)->m_xobject);
		
					{

					}
				}
			}

			////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			//               object[0] hämtar collider objektet från gameobjectet(collider)                                   //////
			//och kollar om den överlappar med ett annat gameobject i samma lista(som den hämtar collider från dess parameter)//////
			////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


			if(m_object.at(i)->Overlap(*m_object.at(z), off)) 
			{ 
				offset += off;


				////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
				//JAG VILL SKICKA COLLIDERNA SOM KOLLIDERADE MED VARANDRA TILL SIN RESPEKTIVE GAMEOBJECT SOM HAR COLLIDERNA SOM PARAMETER///
				////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

				if(m_object.at(z)->m_xobject->GetType() == PLAYER)
				{
					if(off.m_x < 1.0f || off.m_x > 1.0f || off.m_y > 1.0f ||off.m_y < 1.0f )
					{
						//TREE COLLISION
						if(m_object.at(i)->m_xobject->GetType() == LOG)
						{

							m_object.at(z)->m_xobject->m_is_on_log = true;
							m_object.at(z)->m_xobject->SetPosition(m_object.at(i)->m_xobject->GetPosition());
							
							return;

						}else
						{
							
							m_object.at(z)->m_xobject->m_is_on_log = false;
						}



						//WATER
						if(m_object.at(i)->m_xobject->GetType() == WATER && m_object.at(z)->m_xobject->m_is_on_log == false)
						{
							if(!m_object.at(m_object.at(i)->m_xobject->GetType() == LOG)->Overlap(*m_object.at(z), off))
							{
							m_object.at(z)->NotifyParent(m_object.at(z)->m_xobject);
							}
						}

						//	CAR COLLISION
						if(m_object.at(i)->m_xobject->GetType() == CAR)
						{
							m_object.at(z)->NotifyParent(m_object.at(z)->m_xobject);
							score++;
							continue;
						}

						printf("%2d %f %f\n", count, offset.m_x, offset.m_y);

						//GOAL COLLISION
						if(m_object.at(z)->m_xobject->m_is_on_log = true && m_object.at(i)->m_xobject->GetType() == GOAL)
						{
							m_object.at(z)->NotifyParent(m_object.at(z)->m_xobject);

							std::cout << "score: " << score << "\n";
							std::cout << " DU TRAEFFADE MOELET\n";
						}

					}
				}
			}
		}
	}
	if(count > 0) {
		offset /= (float)count;
		offset.m_x=floorf(offset.m_x);
		offset.m_y=floorf(offset.m_y);
	};

}
Collider *CollisionManager::CreateCollider(Vector2 &position, Vector2 &extension)
{

	Collider *collider = new Collider(position, extension);
	m_object.push_back(collider);
	return collider;

}
void CollisionManager::DestroyCollider(Collider *collider)
{
	for (unsigned int i=0; i<m_object.size(); i++)
	{
		if (m_object[i] == collider)
		{
			delete m_object[i];
			m_object[i] = nullptr;
			m_object.erase(m_object.begin()+i);
			break;
		}
	}
}
