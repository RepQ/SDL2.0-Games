#ifndef __SETTINGS_H_
#define __SETTINGS_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>

#define WIDTH_BUTTON (300)
#define HEIGHT_BUTTON (80)
#define MAX_BUTTONS (3)

#define WINDOW_WIDTH (1600)
#define WINDOW_HEIGHT (800)

#define WIDTH_DEMON (100)
#define HEIGHT_DEMON (100)
#define GRAVITY (1550)
#define JUMP (500)
#define VELXDEMON (0)
#define VELYDEMON (0)
#define POSXDEMON ((WIDTH_DEMON) + 50)
#define POSYDEMON ((WINDOW_HEIGHT - HEIGHT_DEMON) / 2)
#define DEMONSPRITES (7)

#define MAX_BACKGROUNDS (8)
#define MAX_LENGHTBACKGROUNDS (19)
#define MAX_SPRITES (18)
#define MAX_LENGHTSPRITES (18)
#define TITLE ("MI PRIMER JUEGO")

#define MAX_OBSTACLES (20)
#define VELXOBSTACLE (200)
#define SEPARATEOBSTACLE (100)
#define POSINIOBSTACLE ((WINDOW_WIDTH + SEPARATEOBSTACLE))

#define MAX_PLAYERS (1)


typedef enum
{
    DEMON = 0,
} players;

// Estructura que define el entorno gráfico (ventana, renderer, texturas a usar
//  superficie, backgrounds, sprites para los players y se encarga de llevar el deltaTime).

typedef struct
{
    int mouseX;
    int mouseY;
    SDL_Scancode KeyPressed;
    TTF_Font *font;
    SDL_Color color;
    /*Varibale encargada de llevar el estado del juego*/
    int state;
    /*Varibale encargada de almacenar el deltaTime correspondiente en cada frame*/
    float deltaTime;
    /*Variables usadas para calcular el deltaTime*/
    Uint64 lastTime;
    Uint64 currentTime;
    /*Puntero que almacena la ventana creada*/
    SDL_Window *window;
    /*Puntero que almacena el renderer creado*/
    SDL_Renderer *render;
    SDL_Surface *textSurface;
    SDL_Texture *textTexture;
    /*          BACKGROUNDS             */
    /*Puntero que almacena un array de surfaces para los backgrounds*/
    SDL_Surface *surface[MAX_BACKGROUNDS];
    /*Puntero que almacena un array de texturas para los backgrounds*/
    SDL_Texture *texture[MAX_BACKGROUNDS];
    /*Arreglo doble que almacena las rutas de todos los sprites de los backgrounds en la carpeta*/
    char backgrounds[MAX_BACKGROUNDS + 1][MAX_LENGHTBACKGROUNDS];

    /*          PLAYERS                 */
    /*Puntero que almacena un array de surfaces para los players*/
    SDL_Surface *surfacePlayer[MAX_SPRITES];
    /*Puntero que almacena un array de texturas para los players*/
    SDL_Texture *texturePlayer[MAX_SPRITES];
    /*Arreglo doble que almacena las rutas de todos los sprites de los players ubicados en la carpeta*/
    char sprites[MAX_SPRITES + 1][MAX_LENGHTSPRITES];
} windowSettings;

/*          FUNCIONES                 */

/*  Funcion encargada de iniciar el entorno visual, es decir, la ventana. y también de
    cargar las texturas y surfaces*/
int InitWindow(char *tile, int width, int height);

/*  Funcion encargada de iniciar las surfaces y texturas de los backgrounds*/
int InitBackground();
/*  Funcion encargada de iniciar las surfaces y texturas de los players*/
int InitSprites();

int InitFont();
void ChangeState(int newState);
float GetTime();
windowSettings *window();
#endif