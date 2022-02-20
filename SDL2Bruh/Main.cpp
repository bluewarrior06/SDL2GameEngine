#include <iostream>
#include <fstream>

#include <vector>
#include <Box2D.h>
#include <SDL.h>

#include "SDLWindow.h"
#include "WindowData.h"
#include "Input.h"
#include "ModFolder.h"


#include <fstream>
#include "boost/archive/text_oarchive.hpp"

#include "BO_WorldObject.h"
#include "BC_Transformation.h"
/*
nuget

SDL2
SDL2 ttf
Box2D
Dirent (didn't currently use in proj)

Boost
Boost Serialization 2022
*/

double a = 0;
double b = 0;
double delta_time = 0;


int main(int argc, char* argv[])
{
	double TIME = 0;
	double TIME_DELTA = 0; //time that is incremented by delta, can cause issues when used in parallel
	//mainwindow
	Window* main_window = new Window("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 512, 512, 512, 512, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);

	WindowData* main_window_data = new WindowData(main_window);

	BO_WorldObject* obj = new BO_WorldObject();

	main_window_data->scene_manager->object_main->AddObject(obj);

	
	//mainloop
	while (main_window->Running)
	{
		TIME += 1;
		TIME_DELTA += 1 * delta_time;
		//performance stuff
		a = SDL_GetPerformanceCounter();

		//execute main event loop
		Input::UpdateMainInput();

		//update game
		main_window_data->scene_manager->UpdateObjects(delta_time);
		main_window_data->scene_manager->UpdateObjectComponents(delta_time);
		main_window_data->world->Step((float32)1. / (float32)60., 6, 2);

		//draw game
		main_window->Clear();
		//main_window_data->Draw();
		main_window_data->scene_manager->DrawObjects(delta_time);
		main_window_data->scene_manager->DrawObjectComponents(delta_time);
		main_window->Render();

		//after performance stuff
		b = SDL_GetPerformanceCounter();
		delta_time = (a - b) / SDL_GetPerformanceFrequency();

		//quitting
		if (Input::IsQuit()){main_window->Running = false;}
		


	}
	delete main_window;
	return 0;
}