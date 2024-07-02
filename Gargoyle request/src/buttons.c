#include <buttons.h>

float posButton[2] = {(WINDOW_WIDTH - WIDTH_BUTTON) / 2, (WINDOW_HEIGHT - HEIGHT_BUTTON) / 2};
int countButton = 0;
Buttons buttons[MAX_BUTTONS];
extern windowSettings settings;

void CreatePlayButton()
{
    Buttons play;
    play.type = PLAY;
    play.posX = posButton[0] - (posButton[0] * 0.4);
    play.posY = posButton[1] + (posButton[1] * 0.5);
    play.mouseOver = 0;
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
    menu.type = MENU;
    menu.posX = posButton[0] + (posButton[0] * 0.4);
    menu.posY = posButton[1] + (posButton[1] * 0.5);
    menu.mouseOver = 0;
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

void CreateBackButton()
{
    Buttons back;

    back.type = BACK;
    back.posX = posButton[0] - (posButton[0] * 0.8);
    back.posY = posButton[1] + (posButton[1] * 0.8);
    back.mouseOver = 0;
    back.actualState = 1;
    back.nextState = 0;
    back.click = 0;

    back.buttonBox.x = back.posX;
    back.buttonBox.y = back.posY;
    back.buttonBox.w = WIDTH_BUTTON;
    back.buttonBox.h = HEIGHT_BUTTON;
    buttons[countButton] = back;
    countButton++;
}

void UpdateButtons()
{
    for (int i = 0; i < MAX_BUTTONS; i++)
    {
        if (settings.mouseX >= buttons[i].posX && settings.mouseX <= buttons[i].posX + WIDTH_BUTTON && settings.mouseY >= buttons[i].posY && settings.mouseY <= buttons[i].posY + HEIGHT_BUTTON)
            buttons[i].mouseOver = 1;
        else
            buttons[i].mouseOver = 0;

        if (EG_CheckClick(&settings.mouseX, &settings.mouseY) && buttons[i].mouseOver)
        {
            buttons[i].click = 1;
        }
        else
            buttons[i].click = 0;
    }
}

void DrawButtons(int state)
{
    for (int i = 0; i < MAX_BUTTONS; i++)
    {
        if (buttons[i].actualState == state)
        {
            switch (buttons[i].mouseOver)
            {
            case 1:
                EG_DrawSprite(7, buttons[i].buttonBox.x, buttons[i].buttonBox.y, buttons[i].buttonBox.w, buttons[i].buttonBox.h, &buttons[i].buttonBox);
                break;
            case 0:
                EG_DrawSprite(8, buttons[i].posX, buttons[i].posY, buttons[i].buttonBox.w, buttons[i].buttonBox.h, &buttons[i].buttonBox);
                break;
            default:
                break;
            }
            
            switch (buttons[i].type)
            {
            case PLAY:
                EG_DrawText("PLAY", &buttons[i].buttonBox);
                break;
            case MENU:
                EG_DrawText("MENU", &buttons[i].buttonBox);
                break;
            case BACK:
                EG_DrawText("BACK", &buttons[i].buttonBox);
                break;
            default:
                break;
            }
        }
    }
}