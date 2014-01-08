// State.h

#pragma once
#include <string>
#include "Engine.h"

class GameObjectManager;

class State
{
public:
	virtual ~State(){};
	/**
	Enters specified State
	**/
	virtual bool Enter(Engine*) =0;
	virtual void Exit() = 0;
	//Update keypresses and internal things
	virtual bool Update(float p_deltatime) =0;
	virtual void Draw() = 0;
	virtual std::string Next() = 0;
	virtual bool IsType(const std::string &type) = 0;

protected:
	GameObjectManager *m_manager;
};
