#ifndef __EASYGRAFICS_H_
#define __EASYGRAFICS_H_

#include <settings.h>
#include <demon.h>
#include <commonSettings.h>
#include <SDL2/SDL.h>

/*Funcion encargada de iniciar el sistema: Ventana, backgrounds y players*/
int EG_InitSystem(char *title, int widthScreen, int heightScreen);
/*Funcion encargada de finalizar el sistema: cerrar la librería y liberar memoria*/
void EG_End();
int EG_GetKeyPress(SDL_Scancode keycode);
void EG_Update();
float EG_DeltaTime();
void EG_DrawBackground(int sprite);
void EG_DrawSprite(int sprite, float posx, float posy, float width, float height,  SDL_Rect *dsrect);
void EG_Render();
int EG_CheckClick();
#endif