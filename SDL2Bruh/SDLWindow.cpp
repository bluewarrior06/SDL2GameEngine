#include "SDLWindow.h"



Window::Window(const char title[], int x, int y, int width, int height, int logical_width, int logical_height, Uint32 flags)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	this->window = SDL_CreateWindow(title, x, y, width, height, flags);
	this->window_renderer = SDL_CreateRenderer(this->window, -1, 0);
	this->window_surface = SDL_GetWindowSurface(this->window);
	
	SDL_RenderSetLogicalSize(this->window_renderer, logical_width,logical_height);
}
Window::~Window()
{
	SDL_FreeSurface(this->window_surface);
	SDL_DestroyRenderer(this->window_renderer);
	SDL_DestroyWindow(this->window);

}


void Window::Clear() {
	SDL_SetRenderDrawColor(this->window_renderer, this->background_r, this->background_g, this->background_b, 1);
	SDL_RenderClear(this->window_renderer);
	SDL_SetRenderDrawColor(this->window_renderer, 0, 0, 0, 0);
}
void Window::Render() { SDL_RenderPresent(this->window_renderer); }



void Window::RenderCopy(SDL_Rect* rect, SDL_Texture* texture)
{
	SDL_RenderCopy(this->window_renderer, texture, nullptr, rect);
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
	this->window_scene_manager = new SceneManager();
	this->gravity = b2Vec2(0, 98);
	this->world = new b2World(this->gravity);
}
WindowData::WindowData(Window* window)
{
	this->window_scene_manager = new SceneManager();
	this->window = window;
	this->gravity = b2Vec2(0, 98);
	this->world = new b2World(this->gravity);
}
WindowData::WindowData(Window* window, b2Vec2 gravity)
{
	this->window_scene_manager = new SceneManager();
	this->window = window;
	this->gravity = gravity;
	this->world = new b2World(this->gravity);
}


WindowData::~WindowData() { delete this->window_scene_manager; }


void WindowData::Update()
{
	this->world->Step(1. / 60., 6, 2);
	this->window_scene_manager->object_group_background->Update();
	this->window_scene_manager->object_group_main->Update();
	this->window_scene_manager->object_group_foreground->Update();


}
void WindowData::Draw(){ 
	this->window_scene_manager->object_group_background->Draw();
	this->window_scene_manager->object_group_main->Draw();
	this->window_scene_manager->object_group_foreground->Draw();
}
