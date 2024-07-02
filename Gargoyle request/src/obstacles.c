#include <obstacles.h>
#include <demon.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

Obstacle obstacles[MAX_OBSTACLES];
extern Demon demon;

void CreateObstacles(float posX, float posY,
                     float velX, float velY, int width, int height, int sprite)
{
    srand(time(NULL));
    for (int i = 0; i < MAX_OBSTACLES; i++)
    {
        int randTopObstacle;
        int randBottomObstacle;
        int randGateObstacle;

        obstacles[i].posX = posX + POSINIOBSTACLE;
        obstacles[i].posY = posY;
        obstacles[i].velX = velX;
        obstacles[i].velY = velY;
        obstacles[i].width = width;
        obstacles[i].height = height;
        obstacles[i].sprite = sprite;

        // Generación aleatoria del tamaño de los obstáculos
        randGateObstacle = SPACE_DEMON + (rand() % (SPACE_DEMON));                 // Espacio entre 50 y 150
        randTopObstacle = 100 + rand() % (WINDOW_HEIGHT - randGateObstacle - 100); // Altura del obstáculo superior

        // Asegurarse de que la altura del obstáculo superior sea un múltiplo de 50
        randTopObstacle = (randTopObstacle / 50) * 50;
        randBottomObstacle = randTopObstacle + randGateObstacle;

        obstacles[i].topObstacle.x = obstacles[i].posX;
        obstacles[i].topObstacle.y = 0;
        obstacles[i].topObstacle.w = obstacles[i].width;
        obstacles[i].topObstacle.h = randTopObstacle;

        obstacles[i].bottomObstacle.x = obstacles[i].posX;
        obstacles[i].bottomObstacle.y = randBottomObstacle;
        obstacles[i].bottomObstacle.w = obstacles[i].width;
        obstacles[i].bottomObstacle.h = WINDOW_HEIGHT - randBottomObstacle;

        obstacles[i].gateObstacle.x = obstacles[i].posX;
        obstacles[i].gateObstacle.y = randGateObstacle;
        obstacles[i].gateObstacle.w = obstacles[i].width;
        obstacles[i].gateObstacle.h = WINDOW_HEIGHT - randTopObstacle - randBottomObstacle;
        posX += SEPARATEOBSTACLE;
    }
}

void UpdateObstacles()
{
    for (int i = 0; i < MAX_OBSTACLES; i++)
    {
        if (EG_CollisionSquare(&demon.demonBox, &obstacles[i].topObstacle))
            demon.isAlive = 0;
        if (EG_CollisionSquare(&demon.demonBox, &obstacles[i].bottomObstacle))
            demon.isAlive = 0;
        // if ((demon.posX + demon.demonBox.w > obstacles[i].posX && demon.posX < obstacles[i].posX + obstacles[i].width) &&
        //     (demon.posY < obstacles[i].topObstacle.h))
        //     demon.isAlive = 0;

        // // Colisiones con el obstáculo inferior
        // if ((demon.posX + demon.demonBox.w > obstacles[i].posX && demon.posX < obstacles[i].posX + obstacles[i].width) &&
        //     (demon.posY + demon.demonBox.h > obstacles[i].bottomObstacle.y))
        //     demon.isAlive = 0;

        obstacles[i].posX -= (obstacles[i].velX * EG_DeltaTime());

        if (obstacles[i].posX <= -(obstacles[i].width))
        {
            float newPosX = obstacles[i].posX;

            for (int j = 0; j < MAX_OBSTACLES; j++)
            {
                if (obstacles[j].posX > newPosX)
                    newPosX = obstacles[j].posX;
            }

            obstacles[i].posX = newPosX + SEPARATEOBSTACLE;
        }
        obstacles[i].topObstacle.x = obstacles[i].posX;
        obstacles[i].bottomObstacle.x = obstacles[i].posX;
    }
}

void DrawObstacles()
{
    for (int i = 0; i < MAX_OBSTACLES; i++)
    {
        int heightTop;
        int heightBottom;

        heightTop = obstacles[i].topObstacle.h / 50;
        heightBottom = obstacles[i].bottomObstacle.h / 50;

        for (int j = 0; j < heightTop + 1; j++)
        {
            if (j == (heightTop))
                EG_DrawSprite(11, obstacles[i].posX, 50 * j, obstacles[i].topObstacle.w, 50, NULL);
            else
                EG_DrawSprite(obstacles[i].sprite, obstacles[i].posX, 50 * j, obstacles[i].topObstacle.w, 50, NULL);
        }

        for (int j = 0; j < heightBottom + 1; j++)
        {
            if (j == 0)
                EG_DrawSprite(10, obstacles[i].posX, obstacles[i].bottomObstacle.y + (50 * j), obstacles[i].bottomObstacle.w, 50, NULL);
            else
                EG_DrawSprite(obstacles[i].sprite, obstacles[i].posX, obstacles[i].bottomObstacle.y + (50 * j), obstacles[i].bottomObstacle.w, 50, NULL);
        }
    }
}