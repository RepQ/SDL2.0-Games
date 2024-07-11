#ifndef __BACKGROUND_H_
#define __BACKGROUND_H_

#include <EasyGrafics.h>
#include <clouds.h>

#define SPACE_CASTLE (1000)

// typedef enum
// {
//     CLOUD = 0,
//     CASTLE,
// } TypeElement;

// typedef struct
// {
//     SDL_Rect element;
//     float posX;
//     float posY;
//     float velX;
//     float velY;
//     int sprite;
//     int type;
// } BackgroundElement;


void CreateElements();
void UpdateElements();
void DrawElements();

#endif