#pragma once
#include <iostream>
#include <Box2D.h>
#include <SDL.h>
#include <SDL_ttf.h>

#include "SceneManager.h"

//window class for rendering a window
class Window
{
public:
	
	SDL_Window* window;
	SDL_Renderer* window_renderer;
	SDL_Surface* window_surface;
	SDL_Event events;

	//game logic
	bool Running = true;
	bool paused = false;

	Uint8 background_r = 0;
	Uint8 background_g = 0;
	Uint8 background_b = 0;

	Window(const char title[], int x, int y, int width, int height, int logical_width, int logical_height, Uint32 flags);
	~Window();

	//screen buffer stuff
	void Clear();
	void Render();

	//void Pause();
	//void Unpause();

	//rendering
	void RenderCopy(SDL_Rect* rect, SDL_Texture* texture);
	void RenderCopyAuto(SDL_Point* point, SDL_Texture* texture, float scale);//automatically renders the texture as the size of the texture

	void RenderText(TTF_Font* font, std::string text, SDL_Color color, SDL_Rect* rect);

	//image loading
	SDL_Surface* LoadSurface(const char path[]);
	SDL_Texture* LoadTexture(const char path[]);

	//gets the size of a texture
	SDL_Point GetTextureSize(SDL_Texture* texture);

	//bool Input();

	//window stuff
	void ResizeWindow(int w, int h);
	void ReposWindow(int x, int y);
	void SetFullscreen(SDL_WindowFlags flags);


	
};

class WindowData
{
public:
	//window pointer
	Window* window;

	WindowData(Window* window);
	~WindowData();

	//scene information
	b2Vec2 gravity;
	b2World* world;
	SceneManager* scene_manager;

	//events
	SDL_Event event;
	bool is_checking_event; //switch for main event to input function event, this would probably break on multiple threads.

	void MainEventUpdate();//sdl2 needs a main event loops or it become brokey and unresponsive.
};

