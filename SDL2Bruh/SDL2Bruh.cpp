#include <iostream>

#include <vector>
#include <Box2D.h>
#include <SDL.h>

#include "SDLWindow.h"

#include "ObjectComponent.h"

#define quote(x) #x

//SDL and Box2D added with NuGet so you might need to get those

float a = 0;
float b = 0;
float delta_time = 0;

int main(int argc, char* argv[])
{
	
	//mainwindow
	Window* main_window = new Window("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 512, 512, 512, 512, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
	WindowData* main_window_data = new WindowData(main_window);
	
	ObjectComponent::Component* c = new ObjectComponent::Component();
	ObjectComponent::Object* o = new ObjectComponent::Object();
	o->AddComponent(c);

	std::cout << typeid(o).name();

	
	//mainloop
	while (main_window->Running)
	{
		
		//performance stuff
		a = SDL_GetPerformanceCounter();

		//update game
		main_window_data->scene_manager->UpdateObjects();
		main_window_data->scene_manager->UpdateObjectComponents();


		//draw game
		main_window->Clear();
		//main_window_data->Draw();
		main_window_data->scene_manager->DrawObjects();
		main_window_data->scene_manager->DrawObjectComponents();
		main_window->Render();

		o->UpdateComponents();


		//after performance stuff
		b = SDL_GetPerformanceCounter();
		delta_time = (a - b) / SDL_GetPerformanceFrequency();
	}
	delete main_window;
	return 0;
}