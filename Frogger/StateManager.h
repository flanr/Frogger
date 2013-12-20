// StateManager.h


#pragma once
#include <vector>

class State;

class StateManager
{
	friend class Engine;
public:
	StateManager();
	~StateManager();

	/**
	Attaches new state
	**/
	void Attach(State *p_state);
	/**
	State Main Loop?
	**/
	void Update(float p_deltatime);
	/**
	Calls Draw from Current State
	**/
	void Draw();
	/**
	Goes through all states, Sets current state to p_type
	then enters state
	**/
	void SetState(const std::string &p_type);

	void ChangeState();
	/**
	return m_current != nullprt;
	**/
	bool IsRunning();

private:
	std::vector<State*> m_states;
	State *m_current;


};
