#include <EasyGrafics.h>

#define mapWidth 24
#define mapHeight 24
#define screenWidth 480
#define screenHeight 480

int running = 1;
SDL_Rect character;
extern windowSettings settings;
float characterX, characterY;

int mapa[mapWidth][mapHeight] =
    {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 0, 0, 0, 0, 3, 0, 3, 0, 3, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 3, 0, 0, 0, 3, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 2, 2, 0, 2, 2, 0, 0, 0, 0, 3, 0, 3, 0, 3, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 4, 4, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 4, 0, 4, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 4, 0, 0, 0, 0, 5, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 4, 0, 4, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 4, 0, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 4, 4, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

int main(int agrc, char **argv)
{
    EG_InitSystem("Juego Raycasting", screenWidth, screenHeight);
    character.w = 10;
    character.h = 10;
    characterX = (screenWidth - character.w) / 2;
    characterY = (screenHeight - character.h) / 2;
    while (running)
    {
        EG_Update();
        float deltaTime;

        deltaTime = EG_DeltaTime();
        if (EG_GetKeyPress(SDL_SCANCODE_W))
            characterY -= (80 * deltaTime);
        if (EG_GetKeyPress(SDL_SCANCODE_S))
            characterY += (80 * deltaTime);
        if (EG_GetKeyPress(SDL_SCANCODE_A))
            characterX -= (80 * deltaTime);
        if (EG_GetKeyPress(SDL_SCANCODE_D))
            characterX += (80 * deltaTime);
        
        for (int i = 0; i < mapWidth; i++)
        {
            for (int j = 0; j < mapHeight; j++)
            {
                SDL_Rect rect1;

                rect1.w = 20;
                rect1.h = 20;
                rect1.x = j * 20;
                rect1.y = i * 20;
                switch (mapa[i][j])
                {
                case 0:
                    SDL_SetRenderDrawColor(settings.render, 0, 0, 0, 0);
                    break;
                case 1:
                    SDL_SetRenderDrawColor(settings.render, 255, 0, 0, 0);
                    break;
                case 2:
                    SDL_SetRenderDrawColor(settings.render, 0, 255, 0, 0);
                    break;
                case 3:
                    SDL_SetRenderDrawColor(settings.render, 0, 0, 255, 0);
                    break;
                case 4:
                    SDL_SetRenderDrawColor(settings.render, 255, 255, 0, 0);
                    break;
                case 5:
                    SDL_SetRenderDrawColor(settings.render, 255, 0, 255, 0);
                    break;
                default:
                    break;
                }
                SDL_RenderFillRect(settings.render, &rect1);
            }
        }
        character.x = (int)characterX;
        character.y = (int)characterY;
        SDL_SetRenderDrawColor(settings.render, 255, 255, 255, 0);
        SDL_RenderFillRect(settings.render, &character);
        EG_Render();
    }
    EG_End();
    return (0);
}