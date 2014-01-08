//Input.cpp

#include "Input.h"

Keyboard::Keyboard() {
	for(int i = 0; i < 256; i++) {
		m_current[i] = false;
		m_previous[i] = false;
	};
};

bool Keyboard::IsDownOnce(int key) const {
	return m_current[key] && !m_previous[key];
};

void Keyboard::PostUpdate() {
	for(int i = 0; i < 256; i++) {
		m_previous[i] = m_current[i];
	};
};

Mouse::Mouse() {
	m_x = 0;
	m_y = 0;

	for(int i = 0; i < MB_COUNT; i++) {
		m_current[i] = false;
		m_previous[i] = false;
	};
};

int Mouse::GetX() const {
	return m_x;
};

int Mouse::GetY() const {
	return m_y;
};

bool Mouse::IsDownOnce(EMouseButton button) const {
	return m_current[button] && !m_previous[button];
};

void Mouse::PostUpdate() {
	for(int i = 0; i < MB_COUNT; i++) {
		m_previous[i] = m_current[i];
	};
};
