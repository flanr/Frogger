// Menu

#pragma once
#include <vector>
#include "Slider.h"

class Menu
{
public:
	Menu(int x, int y, int w, int h);
	~Menu();
	void Run(SDL_Renderer* renderer);

private:
	std::vector<Slider*> sliders;
	void Draw(SDL_Renderer* renderer);
	void HandleInput();
	int m_x, m_y, m_w, m_h;
	int mouseX, mouseY;
	bool running;
	Slider* volume;
	SDL_Rect bgrect;

};




