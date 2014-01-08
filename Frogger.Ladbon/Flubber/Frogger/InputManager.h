//InputManager.h

#pragma once

#include <vector>

class Input;

class InputManager
{
public:
	InputManager();
	~InputManager();

	void Update();

	void KeyPressed(int key);
	void Keypresed(std::vector<int> keys);

	void KeyReleased(int key);
	void KeyReleased(std::vector<int> keys);

private:

};