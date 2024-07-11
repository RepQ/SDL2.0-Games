#include <pointManager.h>

extern Demon demon;
extern Obstacle obstacles[MAX_OBSTACLES];
Points points;
float counter = 0.0f;

void InitScore()
{
    points.number = 0;
    points.toDraw.x = (WINDOW_WIDTH - 200);
    points.toDraw.y = 40;
    points.toDraw.w = 50;
    points.toDraw.h = 50;
}

void UpdateScore()
{
    counter += EG_DeltaTime();

    if (counter >= 1.0f)
        {
            points.number += 1;
            counter = 0.0f;
        }
    // for (int i = 0; i < MAX_OBSTACLES; i++)
    // {
    //     if (EG_CollisionSquare(&demon.demonBox, &obstacles[i].gateObstacle))
    //         points.number += 100;
    // }
    
}

void DrawScore()
{
    char buffer[100];
    sprintf(buffer, "%d", points.number);
    EG_DrawSprite(12, (WINDOW_WIDTH - 250), 50, 200, 50, NULL);
    EG_DrawText(buffer, 0.5, &points.toDraw);
}