#pragma once
#include <iostream>
#include <Box2D.h>
#include <SDL.h>

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

	void Clear();
	void Render();

	//void Pause();
	//void Unpause();

	void RenderCopy(SDL_Rect* rect, SDL_Texture* texture);

	//DO NOT USE STANDALONE
	SDL_Surface* LoadSurface(const char path[]);
	SDL_Texture* LoadTexture(const char path[]);

	//bool Input();

	//window stuff
	void ResizeWindow(int w, int h);
	void ReposWindow(int x, int y);
};

class WindowData
{
public:
	Window* window;
	b2Vec2 gravity;
	b2World* world;

	SceneManager* scene_manager;

	WindowData(Window* window);

	~WindowData();

	void Update();
	void Draw();
};