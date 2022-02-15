#pragma once
#include <iostream>
#include <Box2D.h>
#include <SDL.h>

#include "SceneManager.h"


enum InputType
{
	KEYBOARD,
	MOUSE
};
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

	void Clear();
	void Render();

	void Pause();
	void Unpause();

	void RenderCopy(SDL_Rect* rect, SDL_Texture* texture);

	//DO NOT USE STANDALONE
	SDL_Surface* LoadSurface(const char path[]);
	SDL_Texture* LoadTexture(const char path[]);

	bool Input();
	
};

class WindowData
{
public:
	Window* window;//not actually used for creating a window, but for just pointing to the window
	//^ so its basically useless due to main always having it but I mean, better save than sorry :)))))) :DDDDDDDDDDDDDDD
	SceneManager* window_scene_manager = new SceneManager();

	b2Vec2 gravity;
	b2World* world;

	WindowData();
	WindowData(Window* window);
	WindowData(Window* window, b2Vec2 gravity);

	~WindowData();

	void Update();
	void Draw();
};