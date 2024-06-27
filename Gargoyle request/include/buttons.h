#ifndef __BUTTONS_H_
#define __BUTTONS_H_

#include <EasyGrafics.h>

typedef struct
{
    float posX;
    float posY;
    int actualState;
    int nextState;
    int click;
    int mouseOver;
    SDL_Rect buttonBox;
} Buttons;

void CreatePlayButton();
void CreateMenuButton();
void CreateBackButton();

void DrawButtons(int state);
void UpdateButtons();
#endif