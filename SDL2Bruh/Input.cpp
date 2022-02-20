#include "Input.h"
#include <iostream>

void Input::UpdateMainInput()
{
	SDL_PollEvent(&MAIN_EVENT);
}

//returns true if key is pressed
bool Input::IsKeyDown(InputLayout key)
{
	switch (MAIN_EVENT.type)
	{
	case SDL_KEYDOWN:
		return MAIN_EVENT.key.keysym.scancode == key;
		break;
	}
}

//returns true if key is released
bool Input::IsKeyUp(InputLayout key)
{
	switch (MAIN_EVENT.type)
	{
	case SDL_KEYUP:
		return MAIN_EVENT.key.keysym.scancode == key;
		break;
	}
}
//returns true if key is held
bool Input::IsKeyHeld(InputLayout key)
{
	const Uint8* ks = SDL_GetKeyboardState(NULL);//key state
	return ks[key];
}


bool Input::IsQuit()
{
	switch (MAIN_EVENT.type)
	{
	case SDL_QUIT:
		return true;
		break;
	default:
		return false;
		break;
	}
	//return statement just to be extra extra safe :))))
	return false;
}
bool Input::IsFocused()
{
	
	switch (MAIN_EVENT.type)
	{
	case SDL_WINDOWEVENT_FOCUS_GAINED:
		return true;
		break;
	case SDL_WINDOWEVENT_FOCUS_LOST:
		return false;
		break;
	}
}