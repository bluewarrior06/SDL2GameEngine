#include "InputManager.h"





bool InputManager::KeyPressed(SDL_Keycode key)
{
	return false;
}

bool InputManager::KeyReleased(SDL_Keycode key)
{
	return false;
}

b2Vec2 InputManager::GetMousePosition()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_MOUSEMOTION:
			return b2Vec2(event.motion.x, event.motion.y);
			break;
		}
	}
}