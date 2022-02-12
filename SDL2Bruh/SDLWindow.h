#pragma once
#include <iostream>
#include <Box2D.h>
#include <SDL.h>

#include "Object.h"
#include "ObjectGroup.h"



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

	Window(const char title[], int x, int y, int width, int height, int logical_width, int logical_height, Uint32 flags);
	~Window();

	void Clear();
	void Render();
	void HandleEvents();

	void Pause();
	void Unpause();

	void RenderCopy(SDL_Rect rect, SDL_Rect scale, SDL_Texture texture);

	//DO NOT USE STANDALONE
	SDL_Surface* LoadSurface(const char path[]);
	SDL_Texture* LoadTexture(const char path[]);
};

class WindowData
{
public:
	Window* window;

	ObjectGroup* window_object_group;

	b2Vec2 gravity;

	b2World* world;

	WindowData();
	WindowData(Window* window);
	WindowData(Window* window, b2Vec2 gravity);

	~WindowData();

	void Update();
	void Draw();
};