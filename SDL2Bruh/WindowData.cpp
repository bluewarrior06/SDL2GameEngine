#include "WindowData.h"


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