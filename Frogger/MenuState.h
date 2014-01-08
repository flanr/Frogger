// MenuState.h

#pragma once
#include "State.h"
#include "Engine.h"
#include <SDL.h>
<<<<<<< HEAD
#include "Menu.h"
=======
<<<<<<< HEAD
#include "Menu.h"
=======

class Keyboard;
class Mouse;
>>>>>>> 3f9ee28b9ec02a57b1d1676f76af395488feabee

>>>>>>> 948122011e19de45636c17dd9888beba34d8b268
class MenuState : public State
{
public:


	MenuState(SDL_Renderer* renderer, Keyboard *keyboard, Mouse *mouse, GameObjectManager *manager);
	bool Enter(Engine*);
	void Exit();
	bool Update(float p_deltatime);
	void Draw();
	std::string Next();
	/**
	Returns True if p_type == GameState
	**/
	bool IsType(const std::string &p_type);

private:
	
	
	bool m_done;
	Keyboard *m_keyboard;
	Mouse *m_mouse;

	std::string m_state_next;
	SDL_Renderer* renderer;
	Menu* menu;

};
