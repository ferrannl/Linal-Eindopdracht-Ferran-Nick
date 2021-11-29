#pragma once
#include "../Simulation/World.hpp"
#include "../Simulation/Camera.hpp"
#include <SDL.h>

class MainController {
public:
	const int SCREEN_WIDTH = 1080;
	const int SCREEN_HEIGHT = 1080;

	World* world;
	Camera* camera;


	MainController();

	void input(SDL_Event event);
	int simulate();
	void draw(SDL_Renderer* gRenderer);
};