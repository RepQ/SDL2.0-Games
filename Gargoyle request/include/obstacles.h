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
    SDL_Rect obstacleBox;
} Obstacle;

void CreateObstacle(Obstacle *obstacle, float posX, float posY,
                    float velX, float velY, int widht, int height, int sprite);
void UpdateObstacle(Obstacle *obstacle);
void DrawObstacle(Obstacle *obstacle);
#endif