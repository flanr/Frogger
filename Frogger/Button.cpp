// Button.cpp


#include "Button.h"

Button::Button()
{

}

Button::Button(int x, int y, int w, int h)
{

	SetButton(x, y, w, h);

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
	return button.x;
}

int Button::GetY()
{
	return button.y;
}

int Button::GetW()
{
	return button.w;
}

int Button::GetH()
{
	return button.h;
}

SDL_Rect Button::GetButton()
{
	return button;
}
