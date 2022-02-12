#include "SDLWindow.h"



Window::Window(const char title[], int x, int y, int width, int height, int logical_width, int logical_height, Uint32 flags)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	this->window = SDL_CreateWindow(title, x, y, width, height, flags);
	this->window_renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED);
	this->window_surface = SDL_GetWindowSurface(this->window);
	
	SDL_RenderSetLogicalSize(this->window_renderer, logical_width,logical_height);
}
Window::~Window()
{
	SDL_FreeSurface(this->window_surface);
	SDL_DestroyRenderer(this->window_renderer);
	SDL_DestroyWindow(this->window);

}


void Window::Clear() { SDL_RenderClear(this->window_renderer); }
void Window::Render() { SDL_RenderPresent(this->window_renderer); }

void Window::HandleEvents()
{
	//main event handler
	while (SDL_PollEvent(&this->events))
	{
		switch (this->events.type)
		{
		//quitting
		case SDL_QUIT:
			this->Running = false;
			break;
		case SDL_KEYDOWN:
			if (this->events.key.keysym.sym == SDLK_ESCAPE)
			{
				this->Running = false;
			}
			break;
		}
	}
}

//image loading
SDL_Surface* Window::LoadSurface(const char path[])
{
	return SDL_LoadBMP(path);
}
SDL_Texture* Window::LoadTexture(const char path[])
{
	SDL_Surface* s = SDL_LoadBMP(path);
	SDL_Texture* t = SDL_CreateTextureFromSurface(this->window_renderer, s);
	SDL_FreeSurface(s);
	return t;
}


WindowData::WindowData()
{ 
	this->window_object_group = new ObjectGroup();
	this->gravity = b2Vec2(0, 98);
	this->world = new b2World(this->gravity);
}
WindowData::WindowData(Window* window)
{
	this->window = window;
	this->window_object_group = new ObjectGroup();
	this->gravity = b2Vec2(0, 98);
	this->world = new b2World(this->gravity);
}
WindowData::WindowData(Window* window, b2Vec2 gravity)
{
	this->window = window;
	this->window_object_group = new ObjectGroup();
	this->gravity = gravity;
	this->world = new b2World(this->gravity);
}


WindowData::~WindowData(){delete this->window_object_group;}


void WindowData::Update()
{
	this->window_object_group->Update();
	this->world->Step(1. / 60., 6, 2);
}
void WindowData::Draw(){this->window_object_group->Draw();}
