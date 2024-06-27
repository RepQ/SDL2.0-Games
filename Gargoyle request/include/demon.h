#ifndef __DEMON_H_
#define __DEMON_H_

#include <EasyGrafics.h>

typedef struct
{
    float velX;
    float velY;
    float velJump;
    float posX;
    float posY;
    int sprite;
    int jump;
    SDL_Rect demonBox;
} Demon;

void SetDemonVelJump(Demon *demon, float veljump);
void SetDemonVelX(Demon *demon, float velx);
void SetDemonVelY(Demon *demon, float vely);
void SetDemonPosX(Demon *demon, float posx);
void SetDemonPosY(Demon *demon, float posy);
void SetDemonSprite(Demon *demon, int sprite);
void SetDemonWidth(Demon *demon, int width);
void SetDemonHeight(Demon *demon, int height);

void CreateDemon(Demon *demon, float velx, float vely, float veljump, float posx, float posy,
                 int sprite, int width, int height);
void UpdateDemon(Demon *demon);
void DrawDemon(Demon *demon);
#endif