#include "GameStats.h"
#include <stdio.h>

int	main(int argc, char**argv)
{
	const float	fpsCap = 60.0f;
	const float	fpsCapInMs = 1000.0f / fpsCap;
	uint64_t	start;
	uint64_t	end;
	float		delta;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("Noes posible la iniciacion del modo video: %s\n", SDL_GetError());
		exit (1);
	}
	atexit(SDL_Quit);
	SDL_Surface	*screen;
	screen = SDL_CreateWindow(
			"Main2",
			SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED,
			640,
			480,
			SDL_WINDOW_RESIZABLE
			);
	if (!screen)
	{
		printf("No es posible la creacion de la surface: %s\n", SDL_GetError());
		exit (1);
	}
	SDL_Surface	*image;
	image = SDL_LoadBMP("a.png");
	if (SDL_BlitSurface(image, NULL, screen, NULL) < 0)
		printf("Error image : %s\n", SDL_GetError());
	SDL_UpdateRect(screen, 0, 0, image->w, image->h);
}
