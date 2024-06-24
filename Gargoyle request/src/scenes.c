#include <EasyGrafics.h>
#include <scenes.h>

extern windowSettings settings;
extern Demon demon;

int mouseX;
int mouseY;

int countButton = 0;
float posButton[2] = {(WINDOW_WIDTH - WIDTH_BUTTON) / 2, (WINDOW_HEIGHT - HEIGHT_BUTTON) / 2};
Buttons buttons[MAX_BUTTONS];

void CreatePlayButton()
{
    Buttons play;
    play.posX = posButton[0] - (posButton[0] * 0.4);
    play.posY = posButton[1] + (posButton[1] * 0.5);
    play.actualState = 0;
    play.nextState = 2;
    play.click = 0;

    play.buttonBox.x = play.posX;
    play.buttonBox.y = play.posY;
    play.buttonBox.w = WIDTH_BUTTON;
    play.buttonBox.h = HEIGHT_BUTTON;
    buttons[countButton] = play;
    countButton++;
}

void CreateMenuButton()
{
    Buttons menu;
    menu.posX = posButton[0] + (posButton[0] * 0.4);
    menu.posY = posButton[1] + (posButton[1] * 0.5);
    menu.actualState = 0;
    menu.nextState = 1;
    menu.click = 0;

    menu.buttonBox.x = menu.posX;
    menu.buttonBox.y = menu.posY;
    menu.buttonBox.w = WIDTH_BUTTON;
    menu.buttonBox.h = HEIGHT_BUTTON;
    buttons[countButton] = menu;
    countButton++;
}

void InitScenes()
{
    CreateDemon(&demon, VELXDEMON, GRAVITY, JUMP, POSXDEMON, POSYDEMON, 0, WIDTH_DEMON, HEIGHT_DEMON);
    CreatePlayButton();
    CreateMenuButton();
}

void DrawScene()
{
    switch (settings.state)
    {
    case 0:
        EG_DrawBackground(0);
        DrawButtons(settings.state);
        EG_DrawText("PLAY", &buttons[0].buttonBox);
        EG_DrawText("MENU", &buttons[1].buttonBox);
        ChangeScene();
        if (EG_GetKeyPress(SDL_SCANCODE_SPACE))
        {
            settings.state = 1;
        }
        break;
    case 1:
        EG_DrawBackground(1);
        break;
    case 2:
        EG_DrawBackground(2);
        DrawDemon(&demon);
        UpdateDemon(&demon);
        break;
    default:
        break;
    }
}

void ChangeScene()
{
    for (int i = 0; i < MAX_BUTTONS; i++)
    {
        if (EG_CheckClick() && mouseX >= buttons[i].posX && mouseX <= buttons[i].posX + WIDTH_BUTTON && mouseY >= buttons[i].posY && mouseY <= buttons[i].posY + HEIGHT_BUTTON)
        {
            buttons[i].click = 1;
        }
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

void DrawButtons(int state)
{
    for (int i = 0; i < MAX_BUTTONS; i++)
    {
        if (buttons[i].actualState == state)
        {
            if (mouseX >= buttons[i].posX && mouseX <= buttons[i].posX + WIDTH_BUTTON && mouseY >= buttons[i].posY && mouseY <= buttons[i].posY + HEIGHT_BUTTON)
            {
                EG_DrawSprite(7, buttons[i].buttonBox.x, buttons[i].buttonBox.y, buttons[i].buttonBox.w, buttons[i].buttonBox.h, &buttons[i].buttonBox);
            }
            else
                EG_DrawSprite(8, buttons[i].posX, buttons[i].posY, buttons[i].buttonBox.w, buttons[i].buttonBox.h, &buttons[i].buttonBox);
        }
    }
}
