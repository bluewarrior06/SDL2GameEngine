#pragma once

#include <iostream>
#include <SDL.h>
#include <Box2D.h>



enum CurrentCheckingMode
{
	NONE,
	KEYPRESSED,
	KEYRELEASED,
	MOUSEPRESSED,
	MOUSERELEASED,
	MOUSEMOTION,
	MOUSEVELOCITY,
	MOUSEPOSITION
};


//why do I need to do this.
// holy shit I just compiled it and it worked. and. it. WORKED. FINALLY!

//main input handler
namespace InputManager
{

	bool KeyPressed(SDL_Keycode key);
	bool KeyReleased(SDL_Keycode key);

	b2Vec2 MousePosition();
	bool MouseButtonPressed(SDL_MouseButtonEvent mouse_button);
	bool MouseButtonReleased(SDL_MouseButtonEvent mouse_button);
	bool MouseMotion();
	b2Vec2 MouseVelocity();
	b2Vec2 GetMousePosition();

	template<typename Type, typename Input> static Type _Update(CurrentCheckingMode mode, Input i);
};
