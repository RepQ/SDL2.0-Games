/********************************************************************************
 * 	PRUEBA DE MAIN V1.0 CODIGO CON IMPLEMENTACION LIBRERIA SDL GRAFICOS	*
 * 																		*
 ********************************************************************************/
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <Initialize.h>
#include <player.h>
#include <demon.h>
#include <settings.h>
#include <commonSettings.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>

int main(int argc, char **argv)
{
	if (InitSystem() != 0)
		return (1);
	windowSettings *wSettings;

	wSettings = window();
	SetDemon();
	while (wSettings->running)
	{
		ClearScreen();
		Update();

		// int mouseX;
		// int mouseY;

		// SDL_GetMouseState(&mouseX, &mouseY);
		UpdatePlayer();
		Draw();
		Render();
	}
	FreeMemory();
	return (0);
}
