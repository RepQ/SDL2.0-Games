#ifndef __CLOUDS_H_
#define __CLOUDS_H_

#include <EasyGrafics.h>
#define SPACE_CLOUDS (200)
typedef struct
{
    SDL_Rect element;
    float posX;
    float posY;
    float velX;
    float velY;
    int width;
    int height;
    int sprite;
} Clouds;

void CreateCloud(float posX, float posY, float velX, float velY, int width, int height, int sprite);
void UpdateCloud();
void DrawCloud();
#endif