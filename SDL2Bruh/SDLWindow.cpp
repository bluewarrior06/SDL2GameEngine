#include "SDLWindow.h"

//doesnt use opengl :/
Window::Window(const char title[], int x, int y, int width, int height, int logical_width, int logical_height, Uint32 flags)
{
	//create window
	SDL_Init(SDL_INIT_EVERYTHING);
	this->window = SDL_CreateWindow(title, x, y, width, height, flags);
	this->window_renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED);
	this->window_surface = SDL_GetWindowSurface(this->window);

	
	
	//lock window renderer to size, fixes screen resizing issues.
	SDL_RenderSetLogicalSize(this->window_renderer, logical_width,logical_height);
}
Window::~Window()
{
	//free everything
	SDL_FreeSurface(this->window_surface);
	SDL_DestroyRenderer(this->window_renderer);
	SDL_DestroyWindow(this->window);

}
void Window::Clear() {
	//set render draw color for bg -> clear screen -> reset render draw color
	SDL_SetRenderDrawColor(this->window_renderer, this->background_r, this->background_g, this->background_b, 1);
	SDL_RenderClear(this->window_renderer);
	SDL_SetRenderDrawColor(this->window_renderer, 0, 0, 0, 0);
}
//renders the window
void Window::Render() { SDL_RenderPresent(this->window_renderer); }
//simple drawing method
void Window::RenderCopy(SDL_Rect* rect, SDL_Texture* texture)
{
	
	SDL_RenderCopy(this->window_renderer, texture, nullptr, rect);
}
//image loading
SDL_Surface* Window::LoadSurface(const char path[])
{
	SDL_Surface* ls = SDL_LoadBMP(path);
	SDL_SetColorKey(ls, 1, SDL_MapRGB(this->window_surface->format, 255, 0, 255));
	return ls;
}
SDL_Texture* Window::LoadTexture(const char path[])
{
	SDL_Surface* s = LoadSurface(path);
	SDL_Texture* t = SDL_CreateTextureFromSurface(this->window_renderer, s);
	SDL_FreeSurface(s);
	return t;
}

//repositioning and resizing the window
void Window::ResizeWindow(int w, int h) { SDL_SetWindowSize(this->window, w, h); }
void Window::ReposWindow(int x, int y) { SDL_SetWindowPosition(this->window, x, y); }






//create window data and its data
WindowData::WindowData(Window* window)
{
	
	this->window = window;
	this->scene_manager = new SceneManager();

	this->gravity = b2Vec2(0, 98);

	this->world = new b2World(this->gravity);
	
	this->is_checking_event = true;
}

//free memory that isnt used
WindowData::~WindowData() {
	delete this->scene_manager;
	delete this->world;
}
void WindowData::MainEventUpdate()
{
	if (this->is_checking_event)
	{
		while (SDL_PollEvent(&this->event))
		{
		}
	}
}
//keyboard input
bool WindowData::Input_IsKeyDown(SDL_Keycode key)
{
	bool rv = false;
	this->is_checking_event = false;
	while (SDL_PollEvent(&this->event))
	{
		std::cout << "bruh\n";
		switch (this->event.type)
		{
		case SDL_KEYDOWN:
			this->is_checking_event = true;
			
			rv = this->event.key.keysym.sym == key;
			break;
		}
	}
	this->is_checking_event = true;
	return rv;
}
bool WindowData::Input_IsKeyHeld(SDL_Scancode key)
{
	const Uint8* keys = SDL_GetKeyboardState(NULL);
	return keys[key];
}
bool WindowData::Input_IsKeyUp(SDL_Keycode key)
{
	bool rv = false;
	this->is_checking_event = false;
	while (SDL_PollEvent(&this->event))
	{
		switch (this->event.type)
		{
		case SDL_KEYUP:
			this->is_checking_event = true;

			rv = this->event.key.keysym.sym == key;
			break;
		}
	}
	this->is_checking_event = true;
	return rv;
}
bool WindowData::Input_Action_Quit()
{
	bool rv = false;
	this->is_checking_event = false;
	while (SDL_PollEvent(&this->event))
	{
		switch (this->event.type)
		{
		case SDL_QUIT:
			rv = true;
			break;
		}
	}
	this->is_checking_event = true;
	return rv;
	
}