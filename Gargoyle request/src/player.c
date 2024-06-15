#include <player.h>
#include <commonsettings.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>

playerStates    player[MAX_PLAYERS];
int             playerCount = 0;

void    SetTypePlayer(playerStates *player, int type)
{
    player->typePlayer = type;
}

void    SetUpdatePlayer(playerStates *player, void (*updateFunction)())
{
    player->update = updateFunction;
}

void UpdatePlayer()
{
    if (player->update)
        player->update();
}

void SetPlayerVelX(playerStates *player, float velX)
{
    player->velX = velX;
}

void SetPlayerVelY(playerStates *player, float velY)
{
    player->velY = velY;
}

void SetPlayerPosX(playerStates *player, float posX)
{
    player->posX = posX;
}

void SetPlayerPosY(playerStates *player, float posY)
{
    player->posY = posY;
}

void SetPlayerSprite(playerStates *player, int sprite)
{
    player->sprite = sprite;
}

void SetPlayerWidth(playerStates *player, int width)
{
    player->width = width;
}

void SetPlayerHeight(playerStates *player, int height)
{
    player->height = height;
}

void SetPlayer(int width, int height, float posX, float posY, float velX, float velY)
{
    SetPlayerWidth(player, width);
	SetPlayerHeight(player, height);
	SetPlayerPosX(player, posX);
	SetPlayerPosY(player, posY);
	SetPlayerVelX(player, velX);
	SetPlayerVelY(player, velY);
    player->playerBox.w = player->width;
    player->playerBox.h = player->height;
    player->playerBox.x = (int)player->posX;
    player->playerBox.y = (int)player->posY;
}

void SetDrawPlayer(playerStates *player, void (*paint)())
{
    player->paint = paint;
}

void    DrawPlayer()
{
    if (player->paint)
        player->paint();
}
playerStates    *getPlayer()
{
    return (player);
}