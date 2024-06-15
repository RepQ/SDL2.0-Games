#include <demon.h>

Demon demon;
float counter = 0;

void UpdateDemon()
{
    windowSettings *wSettings;
    playerStates *playerBase;

    float deltaTime;

    playerBase = getPlayer();
    wSettings = window();
    deltaTime = wSettings->deltaTime;
    if (playerBase->jump)
    {
        playerBase->posY -= playerBase->velJump;
    }
    else
    {
        playerBase->posY += playerBase->velY * deltaTime;
    }

    if (playerBase->posY > (WINDOW_HEIGHT - playerBase->playerBox.h))
        playerBase->posY = (WINDOW_HEIGHT - playerBase->playerBox.h);
    else if (playerBase->posY < 0)
        playerBase->posY = 0;
    playerBase->posX += playerBase->velX * deltaTime;

    playerBase->playerBox.x = playerBase->posX;
    playerBase->playerBox.y = playerBase->posY;
}

void DrawDemon()
{
    float deltaTime;
    windowSettings *wSettings;
    playerStates *player;

    wSettings = window();
    player = getPlayer();
    deltaTime = wSettings->deltaTime;
    counter += (deltaTime);

    if (counter >= 0.1f)
    {
        counter = 0.0f;
        player->sprite = (player->sprite + 1) % 7;
    }

    SDL_RenderCopy(wSettings->render, wSettings->texturePlayer[player->sprite], NULL, &player->playerBox);
}

void    SetVelJump(playerStates *player, float velJump)
{
    player->velJump = velJump;
}

void SetDemon()
{
    playerStates *playerBase;

    playerBase = getPlayer();

    SetVelJump(playerBase, JUMP);
    SetPlayerSprite(playerBase, DEMON);
    SetUpdatePlayer(playerBase, UpdateDemon);
    SetDrawPlayer(playerBase, DrawDemon);
    SetPlayer(WIDTH_DEMON, HEIGHT_DEMON, (WINDOW_WIDTH - WIDTH_DEMON) / 2,
              (WINDOW_HEIGHT - HEIGHT_DEMON) / 2, 0, GRAVITY);
}