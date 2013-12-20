// DrawManager.h

#pragma once
class Sprite;
class DrawManager
{
	friend class SpriteManager; // Sprite manager can access Drawmanagers stuff.
public:
	DrawManager();
	~DrawManager();
	/**
	points m_renderer to window, return true.
	if nullprt return false
	**/
	bool Initialize(struct SDL_Window *p_window, int p_width, int p_height);
	/**
	gets rid of the Pointers and nulls them
	**/
	void Cleanup();
	/**
	clears renderer (set background color)
	**/
	void Clear();
	/**
	Updates screen?
	**/
	void Present();
	/**
	Prints Updated screen?
	**/
	void Draw(Sprite *p_sprite, int p_x, int p_y);
private:
	struct SDL_Renderer *m_renderer;
};
