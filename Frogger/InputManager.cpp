//InputManager.cpp

#include "InputManager.h"
#include <SDL.h>
#include "StateManager.h"
#include "Slider.h"
#include <vector>
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

void InputManager::HandleInput(bool *m_running, InputManager *m_input, StateManager *m_state_manager)
{
	SDL_Event event;



	while (SDL_PollEvent(&event))
	{
		/*
		if(event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_k)
		m_state_manager->ChangeState();
		if(event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE)
		{
		*m_running = false;
		}
		else*/	
		if(event.type == SDL_QUIT)
		{
			*m_running=false;
		}
		if(event.type == SDL_KEYDOWN) {
			int index = event.key.keysym.sym & 0xFF;
			m_input->m_current[index] = true;
		}
		else if(event.type == SDL_KEYUP) {
			int index = event.key.keysym.sym & 0xFF;
			m_input->m_current[index] = false;
		}
		else if(event.type == SDL_MOUSEMOTION) {
			m_input->m_x = event.motion.x;
			m_input->m_y = event.motion.y;
		}
		else if(event.type == SDL_MOUSEBUTTONDOWN) {
			if(event.button.button == SDL_BUTTON_LEFT) {
				m_input->m_current[0] = true;
			}
			else if(event.button.button == SDL_BUTTON_RIGHT) {
				m_input->m_current[1] = true;
			};
		}
		else if(event.type == SDL_MOUSEBUTTONUP) {
			if(event.button.button == SDL_BUTTON_LEFT) {
				m_input->m_current[0] = false;
			}
			else if(event.button.button == SDL_BUTTON_RIGHT) {
				m_input->m_current[1] = false;
			};
		};
	}



}





bool InputManager::IsDownOnce(int key) const {
	return m_current[key] && !m_previous[key];
};
bool InputManager::IsDown(int key) const
{
	return m_current[key];
}
bool InputManager::IsUp(int key)
{
	return !m_current[key];
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