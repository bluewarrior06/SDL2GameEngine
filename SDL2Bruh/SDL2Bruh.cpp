#include <iostream>
#include <fstream>

#include <vector>
#include <Box2D.h>
#include <SDL.h>

#include "SDLWindow.h"

#include "ObjectComponent.h"

/*
nuget

SDL2
SDL2 ttf
Box2D
*/

double a = 0;
double b = 0;
double delta_time = 0;


int main(int argc, char* argv[])
{
	double TIME = 0;
	//mainwindow
	Window* main_window = new Window("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 512, 512, 512, 512, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
	WindowData* main_window_data = new WindowData(main_window);
	
	SDL_Rect r;
	r.x = 50;
	r.y = 50;
	r.w = 50;
	r.h = 50;
	SDL_Texture* t = main_window->LoadTexture("Content\\BMP\\Blank.BMP");

	
	//mainloop
	while (main_window->Running)
	{
		TIME += 1 * delta_time;
		//performance stuff
		a = SDL_GetPerformanceCounter();

		//execute main event loop
		main_window_data->MainEventUpdate();

		//update game
		main_window_data->scene_manager->UpdateObjects(delta_time);
		main_window_data->scene_manager->UpdateObjectComponents(delta_time);
		main_window_data->world->Step((float32)1. / (float32)60., 6, 2);

		//draw game
		main_window->Clear();
		//main_window_data->Draw();
		main_window_data->scene_manager->DrawObjects(delta_time);
		main_window_data->scene_manager->DrawObjectComponents(delta_time);
		main_window->RenderCopy(&r, t);
		r.x = sin(TIME * delta_time / 20 ) * 50.0;
		main_window->Render();

		main_window_data->Input_IsKeyDown(SDLK_0);
		//quit handling
		if (main_window_data->Input_Action_Quit())
		{
			main_window->Running = false;
		}


		//after performance stuff
		b = SDL_GetPerformanceCounter();
		delta_time = (a - b) / SDL_GetPerformanceFrequency();
		std::cout << delta_time << std::endl;
	}
	delete main_window;
	return 0;
}