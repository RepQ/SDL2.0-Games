#include <scenes.h>

extern windowSettings settings;
extern Demon demon;
extern Buttons buttons[MAX_BUTTONS];
extern Obstacle obstacles[MAX_OBSTACLES];

void InitScenes()
{
    InitScore();
    CreateDemon(&demon, VELXDEMON, VELYDEMON, JUMP, POSXDEMON, POSYDEMON, 0, WIDTH_DEMON, HEIGHT_DEMON);
    CreateElements();
    CreatePlayButton();
    CreateMenuButton();
    CreateBackButton();
    CreateObstacles(0, 0, VELXOBSTACLE, 0, 50, WINDOW_HEIGHT, 9);
}

void DrawScene()
{
    switch (settings.state)
    {
    case 0:
        EG_DrawBackground(0);
        UpdateButtons();
        DrawButtons(settings.state);
        break;
    case 1:
        EG_DrawBackground(1);
        UpdateButtons();
        DrawButtons(settings.state);
        break;
    case 2:
        EG_DrawBackground(2);
        UpdateScore();
        UpdateElements();
        UpdateObstacles();
        UpdateDemon(&demon);
        DrawElements();
        DrawDemon(&demon);
        DrawObstacles();
        DrawScore();
        break;
    default:
        break;
    }
    ChangeScene();
}

void ChangeScene()
{
    for (int i = 0; i < MAX_BUTTONS; i++)
    {
        switch (buttons[i].click)
        {
        case 1:
            settings.state = buttons[i].nextState;
            break;
        default:
            break;
        }
    }
}


