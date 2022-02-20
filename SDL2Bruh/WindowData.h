#pragma once
#include "SDLWindow.h"
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