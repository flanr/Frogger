// MenuState.cpp

#include "MenuState.h"
#include "Engine.h"
#include <iostream>
#include "Menu.h"
#include "GameObjectManager.h"
#include "Button.h"
#include "Sprite.h"
#include "SpriteManager.h"
#include "DrawManager.h"
#include "SoundManager.h"
MenuState::MenuState(SDL_Renderer* renderer,InputManager *input, Engine* engine)
{
	this->renderer = renderer;
	m_input = input;
	int menuX = engine->GetWidth()/2;
	int menuY = engine->GetHeight()/2;
	menu = new Menu(engine->GetWidth()/2-(menuX/2), engine->GetWidth()/2-(menuY/2), menuX, menuY );
	Play_btn.SetButton(0,0,40,20);
	Next_btn.SetButton(0,100,20,20);
	Prev_btn.SetButton(0,200,20,20);
	Stop_btn.SetButton(0,300,20,20);
	StartState_btn.SetButton(0,400,100,100);
	GameState_btn.SetButton(0,500,100,100);

	// bool MenuStateRunning = false;
}

bool MenuState::Enter(Engine* engine)
{

	m_engine = engine;

	Play_sprite = engine->m_sprite_manager->Load("mjusick.png",0,0,40,20);
	Next_sprite = engine->m_sprite_manager->Load("mjusick.png",60,0,20,20);
	Prev_sprite = engine->m_sprite_manager->Load("mjusick.png",80,0,20,20);
	Stop_sprite = engine->m_sprite_manager->Load("mjusick.png",40,0,20,20);
	StartState_sprite = engine->m_sprite_manager->Load("menu.png",0,0,100,100);
	GameState_sprite = engine->m_sprite_manager->Load("game.png",0,0,100,100);

	m_Current_State = "MenuState";
	// MenuStateRunning = true:
	std::cout << "MenuState now running" << std::endl;
	return false;
}

void MenuState::Exit()
{

}
std::string MenuState::GetCurrentState()
{
	return m_Current_State;
}


bool MenuState::Update(float p_deltatime)
{

	//menu->Run(renderer);

	menu->HandleInput(m_input); ///////////////
	HandleInput();
	menu->UpdateVolume();
	SDL_Delay(10);
	//SDL_RenderPresent(renderer);


	return true;

}

void MenuState::HandleInput()
{
	if (m_input->IsDown(SDLK_k))
	{
		m_engine->m_state_manager.SetState("GameState");
	}
	if (m_input->IsDownOnce(MB_LEFT))
	{
		mouseDown(m_input->GetX(),m_input->GetY());
	}
}
int MenuState::mouseOver(int x, int y)
{
	if ((x > Play_btn.GetX() && x <Play_btn.GetX()+ Play_btn.GetW()) && (y > Play_btn.GetY() && y < Play_btn.GetY()+ Play_btn.GetH())){
		return 1;
	}
	else if ((x > Next_btn.GetX() && x <Next_btn.GetX()+ Next_btn.GetW()) && (y > Next_btn.GetY() && y < Next_btn.GetY()+ Next_btn.GetH())){
		return 2;
	}
	else if ((x > Prev_btn.GetX() && x <Prev_btn.GetX()+ Prev_btn.GetW()) && (y > Prev_btn.GetY() && y < Prev_btn.GetY()+ Prev_btn.GetH())){
		return 3;
	}
	else if ((x > Stop_btn.GetX() && x <Stop_btn.GetX()+ Stop_btn.GetW()) && (y > Stop_btn.GetY() && y < Stop_btn.GetY()+ Stop_btn.GetH())){
		return 4;
	}
	else if ((x > GameState_btn.GetX() && x <GameState_btn.GetX()+ GameState_btn.GetW()) && (y > GameState_btn.GetY() && y < GameState_btn.GetY()+ GameState_btn.GetH())){
		return 5;
	}
	else if ((x > StartState_btn.GetX() && x <StartState_btn.GetX()+ StartState_btn.GetW()) && (y > StartState_btn.GetY() && y < StartState_btn.GetY()+ StartState_btn.GetH())){
		return 6;
	}
	else{
		return 0;
	}
}
void MenuState::mouseDown(int x, int y)
{
	if(mouseOver(x,y) == 1)
	{
		//play
		printf("1 : Play");
		m_engine->m_SoundMgr->PlayPause();
	}

	if(mouseOver(x,y) == 2)
	{
		//next
		
		m_engine->m_SoundMgr->PlayNext();
	}

	if(mouseOver(x,y) == 3)
	{
		//prev
		m_engine->m_SoundMgr->PlayPrev();
	}

	if(mouseOver(x,y) == 4)
	{
		//stop
		printf("4 : Stop");
		m_engine->m_SoundMgr->Stop();
	}

	if(mouseOver(x,y) == 5)
	{

		m_engine->m_state_manager.SetState("GameState");

	}
	if(mouseOver(x,y) == 6)
	{

		m_engine->m_state_manager.SetState("StartState");

	}

}

void MenuState::Draw()
{
	menu->Draw(renderer);
	//	m_engine->m_draw_manager->Draw(backgroundImg,0,0);
	m_engine->m_draw_manager->Draw(Play_sprite,Play_btn.GetX(),Play_btn.GetY());
	m_engine->m_draw_manager->Draw(Next_sprite,Next_btn.GetX(),Next_btn.GetY());
	m_engine->m_draw_manager->Draw(Prev_sprite,Prev_btn.GetX(),Prev_btn.GetY());
	m_engine->m_draw_manager->Draw(Stop_sprite,Stop_btn.GetX(),Stop_btn.GetY());
	m_engine->m_draw_manager->Draw(StartState_sprite,StartState_btn.GetX(),StartState_btn.GetY());
	m_engine->m_draw_manager->Draw(GameState_sprite,GameState_btn.GetX(),GameState_btn.GetY());
	//SDL_SetRenderDrawColor(renderer, 255,0,0,0xff);
	//SDL_RenderFillRect(renderer,&Play_btn.GetButton());
	//SDL_SetRenderDrawColor(renderer, 255,255,0,0xff);
	//SDL_RenderFillRect(renderer,&Next_btn.GetButton());
	//SDL_SetRenderDrawColor(renderer, 255,0,255,0xff);
	//SDL_RenderFillRect(renderer,&Prev_btn.GetButton());
	//SDL_SetRenderDrawColor(renderer, 255,0,0,0xff);
	//SDL_RenderFillRect(renderer,&Stop_btn.GetButton());
	//SDL_SetRenderDrawColor(renderer, 255,255,0,0xff);
	//SDL_RenderFillRect(renderer,&StartState_btn.GetButton());
	//SDL_SetRenderDrawColor(renderer, 255,0,255,0xff);
	//SDL_RenderFillRect(renderer,&GameState_btn.GetButton());
	//SDL_RenderClear(renderer);
}


std::string MenuState::Next()
{
	//	inMenuState = false;
	return "GameState";
}

bool MenuState::IsType(const std::string &p_type)
{
	//return false;
	return p_type.compare("MenuState") == 0;
}


