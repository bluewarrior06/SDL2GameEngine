#pragma once

#include "SDL.h"

#include "Object.h"

//base object for objects that dont move and wont be interacted with
class WorldObject : public Object
{
	SDL_Rect rect;
	float rotation;
};

