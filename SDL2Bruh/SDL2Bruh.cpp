#include <iostream>

#include <vector>
#include <Box2D.h>
#include <SDL.h>
#include <SDL_opengl.h>
#include <gl/GLU.h>

#include "SDLWindow.h"
#include "SceneManager.h"

#include "ObjectGroup.h"
#include "PhysicsObject.h"
#include "TestObject.h"

//SDL and Box2D added with NuGet so you might need to get those

float a = 0;
float b = 0;
float delta_time = 0;

int main(int argc, char* argv[])
{
	//mainwindow
	Window* main_window = new Window("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 512, 512, 512, 512, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);

	WindowData* main_window_data = new WindowData(main_window);


	Object* o = new Object();
	o->name = "bruhg";

	
	
	SDL_Texture* t = main_window->LoadTexture("Content/BMP/Blank.BMP");
	SDL_Rect* r = new SDL_Rect();
	r->x = 0;
	r->y = 0;
	r->w = 100;
	r->h = 100;

	int x, y;
	
	
	//mainloop
	while (main_window->Running)
	{
		
		//performance stuff
		a = SDL_GetPerformanceCounter();

		
		main_window_data->Update();
		main_window->Clear();
		main_window_data->Draw();
			
		main_window->RenderCopy(r, t);
		main_window->Render();

		//after performance stuff
		b = SDL_GetPerformanceCounter();
		delta_time = (a - b) / SDL_GetPerformanceFrequency();
	}
	delete main_window;
	return 0;
}