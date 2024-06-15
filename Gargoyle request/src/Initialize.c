#include <Initialize.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include <stdio.h>

int InitSystem()
{
    windowSettings *wSettings;

    wSettings = window();
    if (InitWindow(TITLE, WINDOW_WIDTH, WINDOW_HEIGHT) != 0)
        return (1);
    wSettings->lastTime = SDL_GetTicks64();
    if (InitBackground(&wSettings) != 0)
        return (1);
    if (InitSprites(&wSettings) != 0)
        return (1);
    InitState();
    return (0);
}

float SetTime()
{
    windowSettings *wSettings;

    wSettings = window();
    wSettings->currentTime = SDL_GetTicks64();
    wSettings->deltaTime = (wSettings->currentTime - wSettings->lastTime) / 1000.0f;
    wSettings->lastTime = wSettings->currentTime;
    return (wSettings->deltaTime);
}

void Update()
{
    windowSettings *wSettings;
    playerStates *player;


    wSettings = window();
    player = getPlayer();
    SetTime();
    SDL_Event Event;

    while (SDL_PollEvent(&Event))
    {
        switch (Event.type)
        {
        case SDL_QUIT:
            wSettings->running = 0;
            break;
        case SDL_KEYDOWN:
            switch (Event.key.keysym.scancode)
            {
            case SDL_SCANCODE_W:
            case SDL_SCANCODE_SPACE:
                player->jump = 1;
                break;
            case SDL_SCANCODE_ESCAPE:
            wSettings->running = 0;
                break;
            default:
                break;
            }
            break;
        case SDL_KEYUP:
            switch (Event.key.keysym.scancode)
            {
            case SDL_SCANCODE_W:
            case SDL_SCANCODE_SPACE:
                player->jump = 0;
                break;

            default:
                break;
            }
        default:
            break;
        }
    }
}

void Draw()
{
    PaintBackground();
    DrawPlayer();
}
void ClearScreen()
{
    windowSettings *wSettings;

    wSettings = window();
    SDL_RenderClear(wSettings->render);
}

void FreeMemory()
{
    windowSettings *wSettings;

    wSettings = window();
    FreeMemSettings(&wSettings);
    SDL_DestroyWindow(wSettings->window);
    SDL_Quit();
}

void Render()
{
    windowSettings *wSettings;

    wSettings = window();
    SDL_RenderPresent(wSettings->render);
}

float getTime()
{
    windowSettings *wSettings;

    wSettings = window();
    return (wSettings->deltaTime);
}