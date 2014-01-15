// Button.cpp


#include "Button.h"

Button::Button()
{

}

Button::Button(int x, int y, int w, int h)
{
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;

}
void Button::SetButton(int x, int y, int w, int h)
{
	button.x = x;
	button.y = y;
	button.h = h;
	button.w = w;
}

Button::~Button(){}
int Button::GetX()
{
	return x;
}

int Button::GetY()
{
	return y;
}

int Button::GetW()
{
	return w;
}

int Button::GetH()
{
	return h;
}

SDL_Rect Button::GetButton()
{
	return button;
}
