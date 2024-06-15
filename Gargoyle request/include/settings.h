#ifndef __SETTINGS_H_
#define __SETTINGS_H_

#include <SDL2/SDL.h>
#include <commonSettings.h>


typedef struct
{
    int             running;
    int             state;
    float           deltaTime;
    Uint64          lastTime;
    Uint64          currentTime;
    SDL_Window      *window;
    SDL_Renderer    *render;
    SDL_Surface     *surface[MAX_BACKGROUNDS];
    SDL_Texture     *texture[MAX_BACKGROUNDS];
    SDL_Surface     *surfacePlayer[MAX_SPRITES];
    SDL_Texture     *texturePlayer[MAX_SPRITES];
    char            backgrounds[MAX_BACKGROUNDS + 1][MAX_LENGHTBACKGROUNDS];
    char            sprites[MAX_SPRITES + 1][MAX_LENGHTSPRITES];
} windowSettings;

int     InitWindow(char *, int, int);
int     InitBackground();
int     InitSprites();
void    InitState();

void    PaintBackground();
void    FreeMemSettings();

float   getTime();
windowSettings  *window();
#endif