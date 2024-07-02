#ifndef __OBSTACLES_H_
#define __OBSTACLES_H_

#include <EasyGrafics.h>

typedef struct
{
    float posX;
    float posY;
    float velX;
    float velY;
    int width;
    int height;
    int sprite;
    SDL_Rect topObstacle;
    SDL_Rect bottomObstacle;
    SDL_Rect gateObstacle;;
} Obstacle;

void CreateObstacles(float posX, float posY,
                    float velX, float velY, int width, int height, int sprite);
void UpdateObstacles();
void DrawObstacles();
#endif