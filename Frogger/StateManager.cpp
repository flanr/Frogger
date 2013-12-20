// StateManager.cpp


#include "StateManager.h"
#include "State.h"
#include <iostream>


StateManager::StateManager()
{
	m_current = nullptr;
}

StateManager::~StateManager()
{
	auto it = m_states.begin();
	while (it != m_states.end())
	{
		delete (*it);
		it++;
	}
	m_states.clear();

}



void StateManager::Attach(State *p_state)
{
	m_states.push_back(p_state);
}

void StateManager::Update(float p_deltatime)
{
	if(m_states.empty())
	{
		return;
	}
	if (!m_current->Update(p_deltatime))
	{
		ChangeState();
	}

}

void StateManager::Draw()
{
	if(m_current ==nullptr)
	{
		return;
	}
	m_current->Draw();
}

void StateManager::ChangeState()
{
	std::string next = m_current->Next();
	if (m_current != nullptr)
	{
		m_current->Exit();
		m_current = nullptr;
	}
	for (unsigned int i = 0; i< m_states.size(); i++)
	{
		if (m_states[i]->IsType(next))
		{
			m_current = m_states[i];
			m_current->Enter();
			return;
		}

	}

}

bool StateManager::IsRunning()
{
	return m_current != nullptr;
}

void StateManager::SetState(const std::string &p_type)
{
	for(unsigned int i=0; i<m_states.size(); i++)
	{
		if(m_states[i]->IsType(p_type))
		{
			m_current = m_states[i];
			m_current->Enter();
			return;
		}

	}

}

