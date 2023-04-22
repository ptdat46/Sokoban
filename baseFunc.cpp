#include<bits/stdc++.h>
#include<SDL.h>
using namespace std;

SDL_Window *window;
SDL_Renderer *renderer;
const int window_width = 600;
const int window_height = 400;
const string window_title = "Game project";

void logSDLError(ostream& os, const string &msg, bool fatal)
{
    os << msg << " Error: " << SDL_GetError() << endl;
    if (fatal)
    {
        SDL_Quit();
        exit(1);
    }
}

void initSDL(SDL_Window* &window, SDL_Renderer* &renderer)
{
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        logSDLError(cout, "SDL_Init", true);
    }
    window = SDL_CreateWindow(window_title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                              window_width, window_height, SDL_WINDOW_SHOWN);
    if (window == nullptr)
    {
        logSDLError(cout, "Create window", true);
    }
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED |
                                  SDL_RENDERER_PRESENTVSYNC);
    if (renderer == nullptr)
    {
        logSDLError(cout, "create renderer", true);
    }
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    SDL_RenderSetLogicalSize(renderer, window_width, window_height);
}

void quitSDL(SDL_Window* window, SDL_Renderer* renderer)
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void waitUntilKeyPressed()
{
    SDL_Event event;
    while (true)
    {
        if (SDL_WaitEvent(&event) != 0 && event.type == SDL_QUIT)
        {
            return;
        }
        SDL_Delay(10);
    }
}

