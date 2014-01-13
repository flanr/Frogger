// StateManager.h


#pragma once
#include <vector>
#include <string>

class State;
class InputManager;

class StateManager
{
	friend class Engine;
public:
	StateManager();
	~StateManager();

	std::string CurrentState();
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

	void SetInput(InputManager *input);

private:
	std::vector<State*> m_states;
	State *m_current;

	InputManager *m_input;



public:
	Engine* engine;


};
