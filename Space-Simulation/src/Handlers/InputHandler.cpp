#include "InputHandler.hpp"
#include <iostream>

void InputHandler::poll_events(Object& object, Matrix* matrix)
{
	if (SDL_PollEvent(&input_event) != 0) {
		switch (input_event.key.keysym.sym) {
		case SDLK_w:
			break;
		case SDLK_a:
			object.transform(matrix);
			break;
		case SDLK_d:
			break;
		case SDLK_s:
			break;
		}
	}
}

InputHandler::InputHandler() : input_event{}
{
}
