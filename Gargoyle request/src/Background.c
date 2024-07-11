#include <Background.h>
#include <stdlib.h>
#include <time.h>


void CreateElements()
{
    srand(time(NULL));
    float posx = (rand() % (WINDOW_WIDTH));
    CreateCloud(posx, 200 ,
                -200, 0, 200, 150, 15);
}

void UpdateElements()
{
    UpdateCloud();
}

void DrawElements()
{
    DrawCloud();
}