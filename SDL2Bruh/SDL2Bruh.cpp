#include <iostream>

#include <vector>
#include <Box2D.h>
#include <SDL.h>

#include "SDLWindow.h"
#include "SceneManager.h"

#include "ObjectGroup.h"
#include "Object.h"
#include "PhysicsObject.h"
#include "TestObject.h"






float a = 0;
float b = 0;
float x = 0;

int main(int argc, char* argv[])
{
	
	//mainwindow
	Window* main_window = new Window("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 512, 512, 256, 256, SDL_WINDOW_SHOWN);

	WindowData* main_window_data = new WindowData(main_window);

	SceneManager* scene_manager = new SceneManager();

	//mainloop
	while (main_window->Running)
	{
		
		//performance stuff
		a = SDL_GetPerformanceCounter();

		main_window->HandleEvents();
		main_window_data->Update();
		main_window->Clear();
		main_window_data->Draw();
		main_window->Render();

		//after performance stuff
		b = SDL_GetPerformanceCounter();
		x = (a - b) / SDL_GetPerformanceFrequency();
	}
	delete main_window;
	return 0;
}