// Slider.h

#pragma once
#include <SDL.h>


class Slider
{
public:
	Slider(int x, int y, int w, int h);
	void moveMouse(int x, int y);
	void mouseDown(int x, int y);
	void mouseUp();
	void draw(SDL_Renderer* renderer);
	void setValue(int);
	int getValue();

private:
	bool mouseOver(int x, int y);
	int x,y,w,h,sw;
	int value;
	SDL_Rect sliderBox;
	SDL_Rect FullSlider, emptySlider;
	bool hovered, selected;
};

