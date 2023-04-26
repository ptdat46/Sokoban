#include<bits/stdc++.h>
#include<SDL_image.h>
#include<SDL.h>
using namespace std;

int const pixel = 25;
SDL_Texture* loadTexture(const char* filename, SDL_Renderer *renderer)
{
    SDL_Texture* newTexture = nullptr;
    SDL_Surface* loadedSurface = IMG_Load(filename);
    if (loadedSurface == nullptr)
    {
        cout << "Unable to load image " << filename << " SDL_Image Error " << IMG_GetError() << endl;
    }
    else
    {
        newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
        if( newTexture == nullptr )
        {
            cout << "Unable to create texture from " << filename << " SDL Error " << SDL_GetError() << endl;
        }
        SDL_FreeSurface(loadedSurface);
    }
    return newTexture;
}

void loadMap(char game_map[24][16], SDL_Renderer *renderer, bool &check_success, int music_is_pause, int option_is_on)
{
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);
    SDL_Texture* wall = loadTexture("Image/wall.png", renderer);
    SDL_Texture* floor = loadTexture("Image/floor.png", renderer);
    SDL_Texture* player = loadTexture("Image/player.bmp", renderer);
    SDL_Texture* box = loadTexture("Image/box.bmp", renderer);
    SDL_Texture* coin = loadTexture("Image/coin.bmp", renderer);
    SDL_Texture* success_box = loadTexture("Image/successbox.bmp", renderer);
    SDL_Texture* undoButton = loadTexture("Image/undoButton.png", renderer);
    SDL_Texture* menuButton = loadTexture("Image/menu.png", renderer);
    SDL_Texture* speakerButton = loadTexture("Image/speaker.png", renderer);
    SDL_Texture* muteButton = loadTexture("Image/muteButton.png", renderer);
    int num_of_successbox = 0;
    for(int j = 0; j < 16; j++)
    {
        for(int i = 0; i < 24; i++)
        {
            SDL_Rect maprect;
            maprect.x = i*pixel;
            maprect.y = j*pixel;
            maprect.w = pixel;
            maprect.h = pixel;
            if(game_map[i][j] == '#')
            {
                SDL_RenderCopy(renderer, wall, NULL, &maprect);
            }
            else if(game_map[i][j] == '_')
            {
                SDL_RenderCopy(renderer, floor, NULL, &maprect);
            }
            else if(game_map[i][j] == 'x')
            {
                SDL_RenderCopy(renderer, floor, NULL, &maprect);
                SDL_RenderCopy(renderer, player, NULL, &maprect);
            }
            else if(game_map[i][j] == 'o')
            {
                SDL_RenderCopy(renderer, floor, NULL, &maprect);
                SDL_RenderCopy(renderer, box, NULL, &maprect);
            }
            else if(game_map[i][j] == '-')
            {
                SDL_SetRenderDrawColor(renderer,255,116,118,255);
                SDL_RenderFillRect(renderer, &maprect);
            }
            else if(game_map[i][j] == 'v')
            {
                SDL_RenderCopy(renderer, floor, NULL, &maprect);
                SDL_RenderCopy(renderer, coin, NULL, &maprect);
            }
            else if(game_map[i][j] == 's')
            {
                num_of_successbox++;
                SDL_RenderCopy(renderer, floor, NULL, &maprect);
                SDL_RenderCopy(renderer, success_box, NULL, &maprect);
            }
        }
    };
    SDL_Rect maprect;
    maprect.x = 550;
    maprect.y = 20;
    maprect.w = pixel;
    maprect.h = pixel;
    SDL_RenderCopy(renderer, undoButton, NULL, &maprect);
    maprect.x = 497;
    maprect.y = 15;
    maprect.w = pixel+12;
    maprect.h = pixel+12;
    SDL_RenderCopy(renderer, menuButton, NULL, &maprect);
    if(music_is_pause%2 == 0)
    {
        maprect.x = 450;
        maprect.y = 15;
        maprect.w = pixel+10;
        maprect.h = pixel+10;
        SDL_RenderCopy(renderer, speakerButton, NULL, &maprect);
        SDL_RenderPresent(renderer);
    }
    else
    {
        maprect.x = 450;
        maprect.y = 15;
        maprect.w = pixel+10;
        maprect.h = pixel+10;
        SDL_RenderCopy(renderer, muteButton, NULL, &maprect);
        SDL_RenderPresent(renderer);
    }
    if(num_of_successbox == 6)
    {
        check_success = true;
    }
    if(option_is_on % 2 != 0) {
        SDL_Texture *option_background = loadTexture("Image/option_background.png", renderer);
        SDL_RenderCopy(renderer, option_background, NULL, NULL);
        SDL_Rect option;
        option.x = 180;
        option.y = 110;
        option.w = 240;
        option.h = 180;
        SDL_Texture *option_board = loadTexture("Image/option.png", renderer);
        SDL_RenderCopy(renderer, option_board, NULL, &option);
        SDL_RenderPresent(renderer);
        SDL_DestroyTexture(option_board);
    }
    SDL_DestroyTexture(wall);
    SDL_DestroyTexture(floor);
    SDL_DestroyTexture(player);
    SDL_DestroyTexture(box);
    SDL_DestroyTexture(coin);
    SDL_DestroyTexture(success_box);
    SDL_DestroyTexture(undoButton);
    SDL_DestroyTexture(menuButton);
    SDL_DestroyTexture(speakerButton);
    SDL_DestroyTexture(muteButton);
}


