#include <obstacles.h>

void CreateObstacle(Obstacle *obstacle, float posX, float posY,
                    float velX, float velY, int width, int height, int sprite)
{
    obstacle->posX = posX + POSINIOBSTACLE;
    obstacle->posY = posY;
    obstacle->velX = velX;
    obstacle->velY = velY;
    obstacle->width = width;
    obstacle->height = height;
    obstacle->sprite = sprite;

    obstacle->obstacleBox.x = obstacle->posX;
    obstacle->obstacleBox.y = obstacle->posY;
    obstacle->obstacleBox.w = obstacle->width;
    obstacle->obstacleBox.h = obstacle->height;
}

void UpdateObstacle(Obstacle *obstacle)
{
    obstacle->posX -= (obstacle->velX * EG_DeltaTime());
}

void DrawObstacle(Obstacle *obstacle)
{
    EG_DrawSprite(9, obstacle->posX, obstacle->posY, obstacle->width, obstacle->height, &obstacle->obstacleBox);
}