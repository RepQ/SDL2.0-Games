#include <demon.h>

float count = 0.0f;

void SetDemonVelX(Demon *demon, float velx)
{
    demon->velX = velx;
}

void SetDemonVelY(Demon *demon, float vely)
{
    demon->velY = vely;
}

void SetDemonPosX(Demon *demon, float posx)
{
    demon->posX = posx;
    demon->demonBox.x = posx;
}

void SetDemonPosY(Demon *demon, float posy)
{
    demon->posY = posy;
    demon->demonBox.y = posy;
}

void SetDemonSprite(Demon *demon, int sprite)
{
    demon->sprite = sprite;
}

void SetDemonWidth(Demon *demon, int width)
{
    demon->demonBox.w = width;
}

void SetDemonHeight(Demon *demon, int height)
{
    demon->demonBox.h = height;
}

void SetDemonVelJump(Demon *demon, float velJump)
{
    demon->velJump = velJump;
}

void CreateDemon(Demon *demon, float velx, float vely, float veljump, float posx, float posy,
                 int sprite, int width, int height)
{
    demon->jump = 0;
    SetDemonVelJump(demon, veljump);
    SetDemonVelX(demon, velx);
    SetDemonVelY(demon, vely);
    SetDemonPosX(demon, posx);
    SetDemonPosY(demon, posy);
    SetDemonSprite(demon, sprite);
    SetDemonWidth(demon, width);
    SetDemonHeight(demon, height);
}

void UpdateDemon(Demon *demon)
{
    float newposY;
    switch (demon->jump)
    {
    case 1:
        demon->posY -= demon->velJump;
        break;
    case 0:
        demon->posY += (demon->velY * EG_DeltaTime());
        break;
    default:
        break;
    }
    if (demon->posY > WINDOW_HEIGHT - HEIGHT_DEMON)
        demon->posY = WINDOW_HEIGHT - HEIGHT_DEMON;
    if (demon->posY < 0)
        demon->posY = 0;
    newposY = demon->posY;
    SetDemonPosY(demon, newposY);
}

void DrawDemon(Demon *demon)
{
    count += EG_DeltaTime();

    if (count >= 0.1f)
    {
        demon->sprite = (demon->sprite + 1) % DEMONSPRITES;
        count = 0.0f;
    }
    EG_DrawSprite(demon->sprite, demon->posX, demon->posY, WIDTH_DEMON, HEIGHT_DEMON, &demon->demonBox);
}