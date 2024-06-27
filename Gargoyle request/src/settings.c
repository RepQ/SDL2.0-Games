#include <settings.h>


extern windowSettings settings;

int InitWindow(char *title, int widthScreen, int heightScreen)
{
    if (SDL_InitSubSystem(SDL_INIT_VIDEO | SDL_INIT_TIMER) != 0)
    {
        printf("Error al cargar la libreria %s\n", SDL_GetError());
        return (1);
    }
    else
    {
        printf("Inicializado con exito\n");
    }

    settings.window = SDL_CreateWindow(title,
                                       SDL_WINDOWPOS_CENTERED,
                                       SDL_WINDOWPOS_CENTERED,
                                       widthScreen, heightScreen, 0);
    if (!settings.window)
    {
        printf("Error al crear la ventana %s\n", SDL_GetError());
        return (1);
    }
    settings.render = SDL_CreateRenderer(settings.window, -1,
                                         SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!settings.render)
    {
        printf("Error al crear el renderer %s\n", SDL_GetError());
        return (1);
    }
    return (0);
}

int InitBackground()
{
    int number;

    number = 0;
    for (int i = 0; i < MAX_BACKGROUNDS; i++)
    {
        char *str = "./Decorados/";
        char fullstr[MAX_LENGHTBACKGROUNDS];

        snprintf(fullstr, sizeof(fullstr), "%s%02d.png", str, number);
        strcpy(settings.backgrounds[i], fullstr);
        settings.backgrounds[i][sizeof(settings.backgrounds[i]) - 1] = '\0';
        printf("Decorado # %d : %s\n", i, settings.backgrounds[i]);
        settings.surface[i] = IMG_Load(settings.backgrounds[i]);
        if (!settings.surface[i])
        {
            printf("Error al crear el surface %s\n", SDL_GetError());
            return (1);
        }
        settings.texture[i] = SDL_CreateTextureFromSurface(settings.render, settings.surface[i]);
        if (!settings.texture[i])
        {
            printf("Error al crear la textura %s\n", SDL_GetError());
            return (1);
        }
        number++;
    }
    strcpy(settings.backgrounds[MAX_BACKGROUNDS], "\0");
    return (0);
}

int InitSprites()
{
    int number;

    number = 0;
    for (int i = 0; i < MAX_SPRITES; i++)
    {
        char *str = "./Sprites/";
        char fullstr[MAX_LENGHTSPRITES];

        snprintf(fullstr, sizeof(fullstr), "%s%03d.png", str, number);
        strcpy(settings.sprites[i], fullstr);
        settings.sprites[i][sizeof(settings.sprites[i]) - 1] = '\0';
        printf("Sprite # %d : %s\n", i, settings.sprites[i]);
        settings.surfacePlayer[i] = IMG_Load(settings.sprites[i]);
        if (!settings.surfacePlayer[i])
        {
            printf("Error al crear el surface %s\n", SDL_GetError());
            return (1);
        }
        settings.texturePlayer[i] = SDL_CreateTextureFromSurface(settings.render, settings.surfacePlayer[i]);
        if (!settings.texturePlayer[i])
        {
            printf("Error al crear la texture %s\n", SDL_GetError());
            return (1);
        }
        number++;
    }
    strcpy(settings.sprites[MAX_SPRITES], "\0");
    number = 0;
    return (0);
}

int InitFont()
{
    if (TTF_Init())
        printf("%s\n", TTF_GetError());
    settings.font = TTF_OpenFont("./font/FreeSans.otf", 10);
    if (!settings.font)
    {
        printf("%s\n", TTF_GetError());
        return (1);
    }
    return (0);
}

float GetTime()
{
    settings.currentTime = SDL_GetTicks64();
    settings.deltaTime = (settings.currentTime - settings.lastTime) / 1000.0f;
    settings.lastTime = settings.currentTime;
    return (settings.deltaTime);
}

void ChangeState(int newState)
{
    settings.state = newState;
}

windowSettings *window()
{
    return (&settings);
}