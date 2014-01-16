// Button.h
#pragma once
#include <SDL.h>


class Button
{
public:
	Button();
	Button(int x, int y, int w, int h);
	~Button();
	void SetButton(int x, int y, int w, int h);
	int GetX();
	void SetX(int x);
	int GetY();
	int GetW();
	int GetH();
	SDL_Rect GetButton();
private:

	SDL_Rect button;
};

