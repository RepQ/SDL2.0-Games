#ifndef __BUTTONS_H_
#define __BUTTONS_H_

#include <EasyGrafics.h>
typedef enum
{
    PLAY = 0,
    MENU,
    BACK
} typeButton;
typedef struct
{
    float posX;
    float posY;
    int actualState;
    int nextState;
    int click;
    int mouseOver;
    typeButton type;
    SDL_Rect buttonBox;
} Buttons;

void CreatePlayButton();
void CreateMenuButton();
void CreateBackButton();

void DrawButtons(int state);
void UpdateButtons();
#endif