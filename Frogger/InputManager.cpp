//InputManager.cpp

#include "InputManager.h"


InputManager::InputManager() {
	//Keyboard

	for(int i = 0; i < 256; i++) {
		m_current[i] = false;
		m_previous[i] = false;
	};
	
	//Mouse

		m_x = 0;
	m_y = 0;

	for(int i = 0; i < MB_COUNT; i++) {
		m_current[i] = false;
		m_previous[i] = false;
	};
};

void InputManager::HandleInput()
{


}

bool InputManager::IsDownOnce(int key) const {
	return m_current[key] && !m_previous[key];
};
bool InputManager::IsDown(int key) const
{
	return m_current[key];
}
void InputManager::PostKeyboardUpdate() {
	for(int i = 0; i < 256; i++) {
		m_previous[i] = m_current[i];
	};

};
int InputManager::GetX() const {
	return m_x;
};
int InputManager::GetY() const {
	return m_y;
};
bool InputManager::IsDownOnce(EMouseButton button) const {
	return m_current[button] && !m_previous[button];
};
bool InputManager::IsDown(EMouseButton button) const
{
	return m_current[button];
};
void InputManager::PostMouseUpdate()
{
	for(int i = 0; i < MB_COUNT; i++) {
		m_previousMouse[i] = m_currentMouse[i];
	};
}