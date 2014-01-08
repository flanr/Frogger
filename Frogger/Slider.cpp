// Slider.cpp

#include <SDL.h>
#include <stdio.h>
#include "Slider.h"


Slider::Slider(int x, int y, int w, int h)
{
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;

	hovered = false;
	selected = false;

	sliderBox.x = x;
	sliderBox.y = y;
	sliderBox.h = h;
	sliderBox.w = w;

	sw = w-w/5; /// Why ?

	FullSlider.y = y+h/3;
	FullSlider.h = h/3;
	FullSlider.x = x+w /10;
	FullSlider.w = sw;

	emptySlider = FullSlider;

	setValue(50);
}

void Slider::setValue(int v)
{
	value = v % 101;
	emptySlider.w = sw*value/100;

	printf("SliderValue changed to: %d \r\n", value);
}

bool Slider::mouseOver(int x, int y)
{
	return (x > this->x && x < this-> x + this->w) && (y > this-> y && y < this-> y + this->h);
}


void Slider::moveMouse(int x, int y)
{
	if(mouseOver(x,y))
	{
		hovered = true;
	}
	else
	{
		hovered = false;
	}

	if (selected)
	{
		int offsetX = x-FullSlider.x;
		if (offsetX <= 0)
		{
			setValue(0);
		} else if (offsetX > sw)
		{
			setValue(100);
		} else
		{
			setValue((offsetX*100) / sw);
		}
	}


}

void Slider::mouseDown(int x, int y)
{
	if(mouseOver(x,y))
	{
		selected = true;
		printf("X:[%d]Y: [%d]\r\n", x, y);
		moveMouse(x, y);
	}

}

void Slider::mouseUp()
{
	selected = false;
}

void Slider::draw(SDL_Renderer* renderer)
{
	SDL_SetRenderDrawColor(renderer, 63,0,0,255);
	SDL_RenderFillRect(renderer, &sliderBox);

	if (selected)
	{
		SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
	} else if (hovered)
	{
		SDL_SetRenderDrawColor(renderer, 127, 127, 0, 255);
	}else
	{
		SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
	}

	SDL_RenderFillRect(renderer, &FullSlider);
	
	SDL_SetRenderDrawColor(renderer, 255, 0, 255, 255);
	SDL_RenderFillRect(renderer, &emptySlider);
}

int Slider::getValue()
{
	return value;
}
