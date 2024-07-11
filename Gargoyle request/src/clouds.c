#include <clouds.h>
#include <stdio.h>

Clouds cloud[10];
float sepx = 0.0f;
int sepY = 0.0f;

void CreateCloud(float posX, float posY, float velX, float velY, int width, int height, int sprite)
{
    for (int i = 0; i < 10; i++)
    {
        sepY += (rand() % (WINDOW_HEIGHT));
        sepY = sepY % WINDOW_HEIGHT;
        cloud[i].posX = posX + sepx;
        cloud[i].posY = posY + sepY;
        cloud[i].velX = velX;
        cloud[i].velY = velY;
        cloud[i].width = width;
        cloud[i].height = height;
        cloud[i].sprite = sprite;

        cloud[i].element.x = cloud[i].posX;
        cloud[i].element.y = cloud[i].posY;
        cloud[i].element.w = cloud[i].width;
        cloud[i].element.h = cloud[i].height;
        sepx += SPACE_CLOUDS;
    }
}

void UpdateCloud()
{
    for (int i = 0; i < 10; i++)
    {
        cloud[i].posX += (cloud[i].velX * EG_DeltaTime());

        if (cloud[i].posX <= -(cloud[i].width))
        {
            float newPosX;

            newPosX = cloud[0].posX;
            for (int i = 0; i < 10; i++)
            {
                if (cloud[i].posX > newPosX)
                    newPosX = cloud[i].posX;
            }
            cloud[i].posX = newPosX + 300;
        }
        cloud[i].element.x = cloud[i].posX;
    }
}

void DrawCloud()
{
    for (int i = 0; i < 10; i++)
    {
        EG_DrawSprite(cloud[i].sprite, cloud[i].element.x, cloud[i].element.y, cloud[i].element.w, cloud[i].element.h, &cloud[i].element);
    }
}