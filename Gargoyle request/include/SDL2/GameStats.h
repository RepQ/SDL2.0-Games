/********************************************************************************
 * 			DEFINICIONES DE ESTRUCTURAS Y ENUMERACIONES		*
 * ******************************************************************************/
#ifndef	GAME_STATS__
#define	GAME_STATS__
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <string.h>
#include <stdio.h>

typedef enum
{
	statePressToPlay,
	statePlaying
} GameState;

typedef struct
{
	SDL_Texture	*texture;
	SDL_Rect	rect;
} Label;

typedef struct
{
	SDL_Window	*window;
	SDL_Renderer	*renderer;
	SDL_Event	event;
	char	title[35];
	int	screenWidth;
	int	screenHeight;
	int	gameOn;
} Game;

typedef struct
{
	SDL_Rect	cards;
	int		type;
	float		life;
} Card;

void	initialize(Game *);
void	initializeCards(Card *, int);

#endif
