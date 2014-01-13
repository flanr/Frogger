//CollisionManager.cpp

#include "CollisionManager.h"
#include "Vector2.h"
#include "GameState.h"
#include "Collider.h"
#include "GameObject.h"
#include "GameObjectManager.h"

CollisionManager::CollisionManager()
{
}


CollisionManager::~CollisionManager()
{

}
void CollisionManager::CheckCollision()
{
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// SÅ MINA COLLIDERS SKA JÄMFÖRAS MED VARANDRA OCH SE OM DE COLLIDERAR, OM DET SKAPAS ETT OFFSET VÄRDE MÅSTE DE SKICKAS TILL DIN PARENT(GAMEOBJECT)///
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	Vector2 offset;
	int count = 0;
	for(auto i = 0UL; i < m_object.size()-1; i++) {
		for(int z = i+1; z < m_object.size(); z++)
		{
			Vector2 off;
			////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			//               object[0] hämtar collider objektet från gameobjectet(collider)                                   //////
			//och kollar om den överlappar med ett annat gameobject i samma lista(som den hämtar collider från dess parameter)//////
			////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			if(m_object.at(i)->Overlap(*m_object.at(z), off)) { 
				offset += off;
				count++;
							printf("%2d %f %f\n", count, offset.m_x, offset.m_y);

				////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
				//JAG VILL SKICKA COLLIDERNA SOM KOLLIDERADE MED VARANDRA TILL SIN RESPEKTIVE GAMEOBJECT SOM HAR COLLIDERNA SOM PARAMETER///
				////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
				
			};
		};
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

/*
bool CollisionManager::IfCollided()
{  

Vector2 offset;
int count = 0;
for(auto i = 0UL; i < c_object.size()-1; i++) {
for(int z = i+1; z < c_object.size(); z++)
{
if(c_object.at(i)->HasCollider()) {
Vector2 off;
if(c_object.at(i)->GetCollider()->Overlap(*c_object.at(z)->GetCollider(), off)) { //object[0] hämtar collider objektet från gameobjectet(collider)
//och kollar om den överlappar med ett annat gameobject i samma lista(som den hämtar collider från dess parameter)
offset += off;
count++;
};
};
};
};
if(count > 0) {
offset /= (float)count;
printf("%2d %f %f\n", count, offset.m_x, offset.m_y);
offset.m_x=floorf(offset.m_x);
offset.m_y=floorf(offset.m_y);
return true;
};
return false;
}

/*Vector2 offset;
if(m_level->CheckCollision(m_player, offset)) {
m_player->SetPosition(m_player->GetCollider()->m_position);

if(offset.m_y < 0.0f) {
printf("--- Y \n");
}
else if(offset.m_y > 0.0f) {
printf("+++ Y\n");
};
if(offset.m_x > 0.0f) {
printf("+++ X\n");
}
else if(offset.m_x < 0.0f) {
printf("--- X\n");
};
};}

void CollisionManager::HasCollided(GameObject *Object1, GameObject *Object2)
{

}
*/