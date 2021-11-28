// Space-Simulation.cpp : This file contains the 'main' function. Program execution begins and ends there.

#define SDL_MAIN_HANDLED
//Using SDL and standard IO
#include <iostream>
#include <string>
#include <deque>
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>

//#include "InputHandler.hpp"

#include "Controllers/MainController.hpp"

//Screen dimension constants
const int SCREEN_WIDTH = 1080;
const int SCREEN_HEIGHT = 1080;

int main(int argc, char* args[])
{
	//InputHandler
	InputHandler input = {};

	//The window we'll be rendering to
	SDL_Window* window = NULL;

	SDL_Renderer* gRenderer = NULL;

	//The surface contained by the window
	SDL_Surface* screenSurface = NULL;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	}
	else
	{
		//Create window
		window = SDL_CreateWindow("Eindopdracht LINAL", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		gRenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
		screenSurface = SDL_GetWindowSurface(window);
		if (window == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		}
		else
		{
			MainController m{};

			/*for (auto o : w.objects) {
				o.transform(o.rotation_matrix_neg_y);
				o.transform(o.rotation_matrix_neg_y);
				o.transform(o.rotation_matrix_neg_y);
				o.transform(o.rotation_matrix_neg_y);
				o.transform(o.rotation_matrix_neg_y);
				o.transform(o.rotation_matrix_neg_y);

				o.transform(o.rotation_matrix_pos_x);
				o.transform(o.rotation_matrix_pos_x);
				o.transform(o.rotation_matrix_pos_x);
				o.transform(o.rotation_matrix_pos_x);
				o.transform(o.rotation_matrix_pos_x);
				o.transform(o.rotation_matrix_pos_x);
			}*/

			//SDL_MessageBoxData* mes = new SDL_MessageBoxData(SDL_MESSAGEBOX_INFORMATION, "Title" , "Text", window);



			SDL_Event event;
			while (true) {
				SDL_Delay(10);
				SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 255);
				SDL_RenderClear(gRenderer);


				m.draw(gRenderer);

				int q = m.simulate();
				if (q == 1) {
					SDL_Delay(10);


					SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 255);
					SDL_RenderClear(gRenderer);
					m.draw(gRenderer);
					SDL_RenderPresent(gRenderer);

					SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Game Over", "Doel vernietigd", window);
					exit(0);
				}
				else if (q == 2) {
					SDL_Delay(10);


					SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 255);
					SDL_RenderClear(gRenderer);
					m.draw(gRenderer);
					SDL_RenderPresent(gRenderer);

					SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Game Over", "Schip kapot", window);
					exit(0);
				}

				if (SDL_PollEvent(&event) != 0) {
					if (event.type == SDL_KEYDOWN) {
						m.input(event);

					}
				}

				SDL_RenderPresent(gRenderer);
			}
		}
	}

	//Destroy window
	//SDL_DestroyRenderer(gRenderer);
	//SDL_DestroyWindow(window);

	//Quit SDL subsystems
	//SDL_Quit();

	return 0;
}