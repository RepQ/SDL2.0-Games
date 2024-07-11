#ifndef __POINTMANAGER_H_
#define __POINTMANAGER_H_

#include <EasyGrafics.h>
#include <demon.h>
#include <obstacles.h>

typedef struct
{
    SDL_Rect toDraw;
    int number;
} Points;
void InitScore();
void UpdateScore();
void DrawScore();
#endif