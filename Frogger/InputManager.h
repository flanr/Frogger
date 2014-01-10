//inputManager.h

#pragma once

#include "StateManager.h"

enum EMouseButton {
	MB_LEFT,
	MB_RIGHT,
	MB_COUNT
};

class InputManager {
	friend class Engine;
public:

	InputManager();

	bool IsDownOnce(int key) const;
	bool IsDown(int key) const;
	
	void PostKeyboardUpdate();
	
	int GetX() const;
	int GetY() const;
	
	bool IsDownOnce(EMouseButton button) const;
	bool IsDown(EMouseButton button) const;
	
	void PostMouseUpdate();
	void HandleInput(bool m_running, InputManager m_input, StateManager m_state_manager);


private:

	bool m_current[256];
	bool m_previous[256];

	bool m_currentMouse[MB_COUNT];
	bool m_previousMouse[MB_COUNT];
	int m_x;
	int m_y;


};
/*class Mouse {
friend class Engine;
public:
Mouse();

int GetX() const;
int GetY() const;
bool IsDownOnce(EMouseButton button) const;
bool IsDown(EMouseButton button) const;
void PostUpdate();

private:
bool m_current[MB_COUNT];
bool m_previous[MB_COUNT];
int m_x;
int m_y;
};
*/