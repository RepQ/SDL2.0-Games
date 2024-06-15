#ifndef __DEMON_H_
#define __DEMON_H_

#include <player.h>

typedef struct
{
    playerStates *player;
    int jump;
    float velJump;
} Demon;

void SetDemon();
void UpdateDemon();
void DrawDemon();
void SetVelJump(playerStates *, float);
#endif