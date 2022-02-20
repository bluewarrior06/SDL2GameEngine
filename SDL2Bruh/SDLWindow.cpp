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
	//create rect position
	SDL_Rect r;
	r.w = rect->w;
	r.h = rect->h;

	r.x = rect->x - (rect->w / 2.0);
	r.y = rect->y - (rect->h / 2.0);

	//render it
	SDL_RenderCopy(this->window_renderer, texture, nullptr, &r);
}
//simple drawing method for automatic scaling
void Window::RenderCopyAuto(SDL_Point* point, SDL_Texture* texture, float scale)
{
	//create rect position
	SDL_Rect r;
	r.w = Window::GetTextureSize(texture).x * scale;
	r.h = Window::GetTextureSize(texture).y * scale;

	r.x = point->x - (r.w / 2.0);
	r.y = point->y - (r.h / 2.0);

	//render it
	SDL_RenderCopy(this->window_renderer, texture, nullptr, &r);
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

//get the size of a texture
SDL_Point Window::GetTextureSize(SDL_Texture* texture)
{
	SDL_Point rp; //return point
	SDL_QueryTexture(texture, NULL, NULL, &rp.x, &rp.y);
	return rp;
}

//repositioning and resizing the window
void Window::ResizeWindow(int w, int h) { SDL_SetWindowSize(this->window, w, h); }
void Window::ReposWindow(int x, int y) { SDL_SetWindowPosition(this->window, x, y); }
void Window::SetFullscreen(SDL_WindowFlags flags) { SDL_SetWindowFullscreen(this->window, flags); }





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
