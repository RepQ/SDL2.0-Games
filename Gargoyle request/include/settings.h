#ifndef __SETTINGS_H_
#define __SETTINGS_H_

#include <EasyGrafics.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <commonSettings.h>


/*          FUNCIONES                 */

/*  Funcion encargada de iniciar el entorno visual, es decir, la ventana. y también de
    cargar las texturas y surfaces*/
int InitWindow(char *tile, int width, int height);

/*  Funcion encargada de iniciar las surfaces y texturas de los backgrounds*/
int InitBackground();
/*  Funcion encargada de iniciar las surfaces y texturas de los players*/
int InitSprites();
void ChangeState(int newState);
float GetTime();
windowSettings *window();
#endif