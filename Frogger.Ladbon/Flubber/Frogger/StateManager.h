// StateManager.h


#pragma once
#include <vector>

class State;
class Keyboard;
class Mouse;

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

	void SetKeyboard(Keyboard *keyboard);
	void SetMouse(Mouse *mouse);

private:
	std::vector<State*> m_states;
	
	Keyboard *m_keyboard;
	Mouse *m_mouse;

	State *m_current;
public:
	Engine* engine;


};
