#include <EasyGrafics.h>

extern windowSettings settings;
extern Demon demon;
extern int running;
extern int mouseX;
extern int mouseY;

int EG_InitSystem(char *title, int widthScreen, int heightScreen)
{
    if (InitWindow(title, widthScreen, heightScreen))
        return (1);
    if (InitBackground())
        return (1);
    if (InitSprites())
        return (1);

    return (0);
}

void EG_End()
{
    for (int i = 0; i < MAX_BACKGROUNDS; i++)
    {
        SDL_FreeSurface(settings.surface[i]);
        SDL_DestroyTexture(settings.texture[i]);
    }
    for (int i = 0; i < MAX_SPRITES; i++)
    {
        SDL_FreeSurface(settings.surfacePlayer[i]);
        SDL_DestroyTexture(settings.texturePlayer[i]);
    }
    SDL_DestroyWindow(settings.window);
    SDL_Quit();
}

void EG_DrawBackground(int sprite)
{
    SDL_RenderCopy(settings.render, settings.texture[sprite], NULL, NULL);
}

void EG_DrawSprite(int sprite, float posx, float posy, float width, float height, SDL_Rect *dsrect)
{
    if (!dsrect)
    {
        SDL_Rect rect2;

        rect2.x = posx;
        rect2.y = posy;
        rect2.w = width;
        rect2.h = height;
        SDL_RenderCopy(settings.render, settings.texturePlayer[sprite], NULL, &rect2);
    }
    else
    {
        SDL_Rect *rect;

        rect = dsrect;

        rect->x = posx;
        rect->y = posy;
        rect->w = width;
        rect->h = height;
        SDL_RenderCopy(settings.render, settings.texturePlayer[sprite], NULL, rect);
    }
}

void EG_Render()
{
    SDL_RenderPresent(settings.render);
}

int EG_GetKeyPress(SDL_Scancode keyCode)
{
    if (keyCode == settings.KeyPressed)
        return (1);
    else
        return (0);
}

void EG_Update()
{
    GetTime();
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
            running = 0;
            break;
        case SDL_KEYDOWN:
            settings.KeyPressed = event.key.keysym.scancode;
            if (event.key.keysym.scancode == SDL_SCANCODE_SPACE)
                demon.jump = 1;
            else if (event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
                running = 0;
            break;
        case SDL_KEYUP:
            settings.KeyPressed = 0;
            if (event.key.keysym.scancode == SDL_SCANCODE_SPACE)
                demon.jump = 0;
            break;
        default:
            break;
        }
    }
}

float EG_DeltaTime()
{
    return (settings.deltaTime);
}

int EG_CheckClick()
{
    return (SDL_GetMouseState(&mouseX, &mouseY));
}