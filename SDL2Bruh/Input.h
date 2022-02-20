#pragma once
#include <SDL.h>
#include <vector>

static bool updaing_main_input = true;
static SDL_Event MAIN_EVENT;

enum InputLayout
{
	//directions
	UP = SDL_SCANCODE_UP,
	DOWN = SDL_SCANCODE_DOWN,
	LEFT = SDL_SCANCODE_LEFT,
	RIGHT = SDL_SCANCODE_RIGHT,

	//interaction
	ACCEPT = SDL_SCANCODE_Z,
	DECLINE = SDL_SCANCODE_X



};
class Input
{
public:
	//update all events
	static void UpdateMainInput();

	//main input handling
	static bool IsKeyDown(InputLayout key);
	static bool IsKeyUp(InputLayout key);
	static bool IsKeyHeld(InputLayout key);
	
	//window events
	static bool IsQuit();

	static bool IsFocused();
	

};

