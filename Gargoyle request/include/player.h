#ifndef __PLAYER_H_
#define __PLAYER_H_

#include <SDL2/SDL.h>
#include <commonSettings.h>
#include <settings.h>

struct  playerStates;
typedef struct
{
    float       velX;
    float       velY;
    float       posX;
    float       posY;
    int         sprite;
    int         width;
    int         height;
    int         typePlayer;
    int         jump;
    float       velJump;
    SDL_Rect    playerBox;
    void        (*update)();
    void        (*paint)();
} playerStates;

void    SetTypePlayer(playerStates *, int);
void    SetUpdatePlayer(playerStates *, void (*update)());
void    SetPlayerVelX(playerStates *, float);
void    SetPlayerVelY(playerStates *, float);
void    SetPlayerPosX(playerStates *, float);
void    SetPlayerPosY(playerStates *, float);
void    SetPlayerSprite(playerStates *, int);
void    SetPlayerWidth(playerStates *, int);
void    SetPlayerHeight(playerStates *, int);


void    SetPlayer(int, int, float, float, float, float);
void    SetDrawPlayer(playerStates *, void (*paint)());
void    DrawPlayer();
void    UpdatePlayer();

void    DrawPlayer();
playerStates    *getPlayer();

#endif