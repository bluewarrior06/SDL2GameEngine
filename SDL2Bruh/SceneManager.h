#pragma once

#include "SDLWindow.h"
class SceneManager
{
	Window* window;
	WindowData* window_data;

	void Load();//clears the scene and loads the next scene
	void Overload();//loads the next scene without clearing the last scene
	void Clear();
};

