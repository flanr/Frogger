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

	bool KeyPressed(int key);
	bool Keypresed(std::vector<int> keys);

	bool KeyReleased(int key);
	bool KeyReleased(std::vector<int> keys);

private:

};