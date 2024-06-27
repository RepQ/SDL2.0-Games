#include <scenes.h>


windowSettings settings;
Demon demon;
Buttons buttons[MAX_BUTTONS];
Obstacle obstacles[MAX_OBSTACLES];

float posX = 0;
void InitScenes()
{
    CreateDemon(&demon, VELXDEMON, VELYDEMON, JUMP, POSXDEMON, POSYDEMON, 0, WIDTH_DEMON, HEIGHT_DEMON);
    CreatePlayButton();
    CreateMenuButton();
    CreateBackButton();
    for (int i = 0; i < MAX_OBSTACLES; i++)
    {
        CreateObstacle(&obstacles[i], posX, 0, VELXOBSTACLE, 0, 50, 300, 9);
        posX += SEPARATEOBSTACLE;
    }
    
}

void DrawScene()
{
    switch (settings.state)
    {
    case 0:
        EG_DrawBackground(0);
        UpdateButtons();
        DrawButtons(settings.state);
        EG_DrawText("PLAY", &buttons[0].buttonBox);
        EG_DrawText("MENU", &buttons[1].buttonBox);
        break;
    case 1:
        EG_DrawBackground(1);
        UpdateButtons();
        DrawButtons(settings.state);
        EG_DrawText("BACK", &buttons[2].buttonBox);
        break;
    case 2:
        EG_DrawBackground(2);
        for (int i = 0; i < MAX_OBSTACLES; i++)
        {
            UpdateObstacle(&obstacles[i]);
        }
        for (int i = 0; i < MAX_OBSTACLES; i++)
        {
            DrawObstacle(&obstacles[i]);
        }
        
        UpdateDemon(&demon);
        DrawDemon(&demon);
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


