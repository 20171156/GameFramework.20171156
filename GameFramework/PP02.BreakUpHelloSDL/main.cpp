#include<SDL.h>

//int main(int argc, char* args[])
//{
//
//    if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
//    {
//
//        g_pWindow = SDL_CreateWindow("PP01.HelloSDL",
//            SDL_WINDOWPOS_CENTERED,
//            SDL_WINDOWPOS_CENTERED,
//            640, 480, SDL_WINDOW_SHOWN);
//
//        if (g_pWindow != 0) {
//            g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, 0);
//        }
//    }
//    else {
//        return 1;
//    }
//
//    SDL_SetRenderDrawColor(g_pRenderer, 0, 0, 0, 255);
//    SDL_RenderClear(g_pRenderer);
//    SDL_RenderPresent(g_pRenderer);
//    SDL_Delay(5000);
//    SDL_Quit();
//    return 0;
//} ����� �и��Ѵ�

SDL_Window*g_pWindow = 0;
SDL_Renderer*g_pRenderer = 0;

void init() {}
void render() {}
void update() {}
void handleEvents() {}
void clean() {}

bool g_bRunning = true;

int main()
{
    init();
    while (g_bRunning)
    {
        handleEvents();
        update();
        render();
    }
    clean();
    return 0;
}

bool init(const char* title, int xpos, int ypos, int width, int height, int flags)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
    {
        g_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

        if (g_pWindow != 0)
        {
            g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, 0);
        }
    }

    else
    {
        return false;
    }
    return true;
}

void render()
{
    SDL_SetRenderDrawColor(g_pRenderer, 0, 0, 0, 255);
    SDL_RenderClear(g_pRenderer);
    SDL_RenderPresent(g_pRenderer);
}

int main(int argc, char *argv[])
{
    if (init("Chapter 1 : Setting up SDL",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        640, 480, SDL_WINDOW_SHOWN))
    {
        g_bRunning = true;
    }
    else
    {
        return 1;
    }

    while (g_bRunning)
    {
        render();
    }

    SDL_Quit();
    return 0;
}