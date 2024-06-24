/********************************************************************************
 * 	PRUEBA DE MAIN V1.0 CODIGO CON IMPLEMENTACION LIBRERIA SDL GRAFICOS	*
 * 																		*
 ********************************************************************************/
#include <EasyGrafics.h>
#include <commonSettings.h>
#include <scenes.h>
#include <demon.h>
#include <settings.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include <stdio.h>

windowSettings settings;
Demon demon;
int running;

int main(int argc, char **argv)
{

	EG_InitSystem(TITLE, WINDOW_WIDTH, WINDOW_HEIGHT);
	InitScenes();
	running = 1;
	while (running)
	{
		EG_Update();

		DrawScene();
		EG_Render();
	}
	EG_End();
	return (0);
}
