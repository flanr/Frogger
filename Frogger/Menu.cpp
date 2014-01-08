// Menu.cpp


#include <SDL.h>
#include "Menu.h"
#include "GlobalGameConfig.h"
#include "Slider.h"

Menu::Menu(int m_x, int m_y, int m_w, int m_h)
{
	this->m_x = m_x;
	this->m_y = m_y;
	this->m_w = m_w;
	this->m_h = m_h;

	running = false;

	bgrect.x = m_x;
	bgrect.y = m_y;
	bgrect.h = m_h;
	bgrect.w = m_w;
	int sliderCount = 8;
	int offset = (m_h/sliderCount+1)/(sliderCount+1);
	printf("%d", offset);
	for(int n = 0; n < sliderCount; ++n){
			sliders.push_back(new Slider(m_x + 20, m_y + offset*((n)) + offset/2 + (m_h/(sliderCount+1))*n, m_w - 40, m_h / (sliderCount + 1)));
	}
	sliders[0]->setValue(40);
	GlobalGameConfig.musicVolume = sliders[0]->getValue();
	sliders[1]->setValue(66);

	
	/*sliders.push_back(new Slider(m_x + 20, m_y + offset, m_w -40, m_h / (sliderCount+1))); // Pushback Slider* 
	sliders.push_back(new Slider(m_x + 20, m_y + offset + 1*m_h /(sliderCount+1)+(offset*1), m_w -40, m_h/(sliderCount+1)));
	sliders.push_back(new Slider(m_x + 20, m_y + offset + 2*m_h /(sliderCount+1)+(offset*2), m_w -40, m_h/(sliderCount+1)));
	sliders.push_back(new Slider(m_x + 20, m_y + offset + 3*m_h /(sliderCount+1)+(offset*3), m_w -40, m_h/(sliderCount+1)));
	sliders.push_back(new Slider(m_x + 20, m_y + offset + 4*m_h /(sliderCount+1)+(offset*4), m_w -40, m_h/(sliderCount+1)));
	*/
}


Menu::~Menu()
{
	for(Slider* s : sliders)
	{
		delete s;
	}
}

void Menu::Run(SDL_Renderer* renderer)
{
	running = true;
	while (running)
	{
		Draw(renderer);
		HandleInput();
		SDL_RenderPresent(renderer);
		SDL_Delay(10);
	}
}

void Menu::Draw(SDL_Renderer* renderer)
{
	// Draw Background Box

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderFillRect(renderer, &bgrect);
	//
	for(Slider* s : sliders)
	{
		s->draw(renderer);
	}


}

void Menu::HandleInput()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
//keypress
		if (event.type == SDL_KEYDOWN)
		{
			if (event.key.keysym.sym == 'm')
			{

				running = false;
			}
		}
//Mouse
		if (event.type == SDL_MOUSEMOTION)
		{
			mouseX = event.motion.x;
			mouseY = event.motion.y;
			for (Slider* s : sliders)
			{
				s->moveMouse(mouseX, mouseY);
			}

		}
		if (event.type == SDL_MOUSEBUTTONDOWN)
		{
			if (event.button.button == SDL_BUTTON_LEFT)
			{
				for(Slider* s : sliders)
				{
					s->mouseDown(mouseX,mouseY);
				}

			}
		}
		if (event.type == SDL_MOUSEBUTTONUP)
		{
			if (event.button.button == SDL_BUTTON_LEFT)
			{
				for(Slider* s : sliders)
				{
					s->mouseUp();
				}

			}
		}
	}
}
