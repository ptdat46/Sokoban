#include <iostream>
#include<SDL.h>
#include<SDL_image.h>
#include<bits/stdc++.h>
#include<fstream>
#include<SDL_mixer.h>
#include<deque>
#include "movement.h"
#include "loadMap.h"
#include "baseFunc.h"
#include<SDL_ttf.h>
using namespace std;

/*Hàm báo lỗi*/
/*Hàm khởi tạo*/
const int window_width = 600;
const int window_height = 400;
const int pixel = 25;
char tmp_map[24][16];
SDL_Event e;
const string window_title = "Game project";

void mouseLeftClicked(SDL_Renderer *renderer, SDL_Event e, char game_map[24][16], vector<vector<char>> game_map_saved, deque<vector<vector<char>>> &undo_list,
                    int &undo_times, int &is_pause, vector<obj> &arr_box, vector<char> &row, obj &player, int &option_is_on);
void gamePlay(SDL_Window* window, SDL_Renderer* renderer, SDL_Event &e, string s, char (&tmp_map)[24][16]);
void Start(SDL_Window* window, SDL_Renderer* renderer, SDL_Event &e);
void gameMenu(SDL_Window *window, SDL_Renderer *renderer, SDL_Event &e);
void loadFont(string s, int x, int y, int w, int h, SDL_Renderer *renderer);
void Option(int &option_is_on, SDL_Event &e, SDL_Window *window, SDL_Renderer *renderer, char (&tmp_map)[24][16]);

int main(int argc, char* argv[])
{
    SDL_Window* window;
    SDL_Renderer* renderer;
    initSDL(window, renderer);
    SDL_RenderClear(renderer);
    Mix_Music *gMusic = NULL;
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
    gMusic = Mix_LoadMUS( "background_music.mp3" );
    Mix_PlayMusic(gMusic, -1 );
    Start(window, renderer, e);
    waitUntilKeyPressed();
    quitSDL(window, renderer);
    return 0;
}

void mouseLeftClicked(SDL_Renderer *renderer, SDL_Event e, char game_map[24][16], vector<vector<char>> game_map_saved, deque<vector<vector<char>>> &undo_list,
                    int &undo_times, int &is_pause, vector<obj> &arr_box, vector<char> &row, obj &player, int &option_is_on)
{
    if(e.button.x <= 570 && e.button.x >= 550 && e.button.y <= 40 && e.button.y >= 20 && !undo_list.empty() && undo_times > 0)
    {
        arr_box.clear();
        game_map_saved.clear();
        game_map_saved = undo_list.back();
        undo_list.pop_back();
        for(int j = 0; j < 16; j++)
        {
            row.clear();
            row = game_map_saved[j];
            for(int i = 0; i < 24; i++)
            {
                game_map[i][j] = row[i];
                if(game_map[i][j] == 'x')
                {
                    player.x = i;
                    player.y = j;
                }
                if(game_map[i][j] == 'o')
                {
                    obj box{i, j, 'o'};
                    arr_box.push_back(box);
                }
            }
        }
        SDL_Rect maprect;
        maprect.x = 550;
        maprect.y = 20;
        maprect.w = pixel;
        maprect.h = pixel;
        SDL_Texture *undoButton_clicked = loadTexture("Image/undoButton_clicked.png", renderer);
        SDL_RenderCopy(renderer, undoButton_clicked, NULL, &maprect);
        SDL_RenderPresent(renderer);
        undo_times--;
    }
    if(e.button.x <= 480 && e.button.x >= 450 && e.button.y <= 45 && e.button.y >= 15)
    {
        if(is_pause%2 == 0)
        {
            Mix_PauseMusic();
        }
        else
        {
            Mix_ResumeMusic();
        }
        is_pause++;
    }
    if(e.button.x <= 534 && e.button.x >= 497 && e.button.y <= 52 && e.button.y >= 15)
    {
        option_is_on++;
    }

}

void gamePlay(SDL_Window* window, SDL_Renderer* renderer, SDL_Event &e, string s, char (&tmp_map)[24][16])
{
    char game_map[24][16];
    bool check_success = false;
    int is_pause = 0;
    int option_is_on = 0;
    bool running = true;
    int undo_times = 3;
    ifstream file("map" + s + ".txt");
    if(s == "Restart")
    {
        for(int j = 0; j < 16; j++)
        {
            for(int i = 0; i < 24; i++)
            {
                game_map[i][j] = tmp_map[i][j];
            }
        }
    }
    vector<obj> arr_coin;
    vector<obj> arr_box;
    deque<vector<vector<char>>> undo_list;
    vector<vector<char>> game_map_saved;
    vector<char> row;
    obj player;
    for(int j = 0; j < 16; j++)
    {
        for(int i = 0; i < 24; i++)
        {
            if(s != "Restart")
            {
                file >> game_map[i][j];
                tmp_map[i][j] = game_map[i][j];
            }
            if(game_map[i][j] == 'x')
            {
                player.x = i;
                player.y = j;
                player.z = 'x';
            }
            else if(game_map[i][j] == 'o')
            {
                obj box{i, j, 'o'};
                arr_box.push_back(box);
            }
            else if(game_map[i][j] == 'v')
            {
                obj coin{i, j, 'v'};
                arr_coin.push_back(coin);
            }
        }
    }
    //Module load map (sử dụng load map đầu game và load map sau khi undo)
    loadMap(game_map, renderer, check_success, is_pause, option_is_on);
    /*Game loop*/
    while(running)
    {
        bool undo = false;
        SDL_Delay(1);
        if ( SDL_WaitEvent(&e) == 0) continue;
        if(e.type == SDL_QUIT) quitSDL(window, renderer);
        if (e.type == SDL_KEYDOWN)
        {
            if (e.key.keysym.sym == SDLK_LEFT)
            {
                moveLeft(player, arr_coin, arr_box, game_map, undo_list, game_map_saved, row);
            }
            else if (e.key.keysym.sym == SDLK_RIGHT)
            {
                moveRight(player, arr_coin, arr_box, game_map, undo_list, game_map_saved, row);
            }
            else if (e.key.keysym.sym == SDLK_DOWN)
            {
                moveDown(player, arr_coin, arr_box, game_map, undo_list, game_map_saved, row);
            }
            else if (e.key.keysym.sym == SDLK_UP)
            {
                moveUp(player, arr_coin, arr_box, game_map, undo_list, game_map_saved, row);
            }
        }
        if(e.type == SDL_MOUSEBUTTONDOWN)
        {
            if(e.button.button == SDL_BUTTON_LEFT)
            {
                mouseLeftClicked(renderer, e, game_map, game_map_saved, undo_list, undo_times, is_pause, arr_box, row, player, option_is_on);
            }
        }
        if(check_success == false && (e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_KEYDOWN))
        {
            loadMap(game_map, renderer, check_success, is_pause, option_is_on);
            if(option_is_on % 2 != 0)
            {
                Option(option_is_on, e, window, renderer, tmp_map);
                loadMap(game_map, renderer, check_success, is_pause, option_is_on);
            }

        }
        else if(check_success == true)
        {
            SDL_Texture* youWin = loadTexture("Image/youWin.png", renderer);
            SDL_RenderCopy(renderer, youWin, NULL, NULL);
            SDL_RenderPresent(renderer);
        }
    }
}

void Start(SDL_Window* window, SDL_Renderer* renderer, SDL_Event &e)
{
    SDL_Texture *main_background = loadTexture("Image/main_background.png", renderer);
    SDL_RenderCopy(renderer, main_background, NULL, NULL);
    SDL_Rect startButton;
    startButton.x = 250;
    startButton.y = 270;
    startButton.w = 100;
    startButton.h = 100;
    while(true) {
        SDL_Delay(10);
        if ( SDL_WaitEvent(&e) == 0) continue;
        if (e.type == SDL_QUIT) quitSDL(window, renderer);
        if(e.type == SDL_MOUSEBUTTONDOWN)
        {
            if(e.button.button == SDL_BUTTON_LEFT)
            {
                if(e.button.x <= 350 && e.button.x >= 250 && e.button.y <= 370 && e.button.y >= 270)
                {
                    //gamePlay(window, renderer, e, s);
                    gameMenu(window, renderer, e);
                    quitSDL(window, renderer);
                }
            }
        }
        if(e.type == SDL_MOUSEMOTION)
        {
            if(e.button.x <= 350 & e.button.x >= 250 && e.button.y <= 370 && e.button.y >= 270)
            {
                SDL_Texture *start_button_hover = loadTexture("Image/start_button_hover.png", renderer);
                SDL_RenderCopy(renderer, start_button_hover, NULL, &startButton);
                SDL_RenderPresent(renderer);
            }
            else
            {
                SDL_Texture *start_button = loadTexture("Image/start_button.png", renderer);
                SDL_RenderCopy(renderer, start_button, NULL, &startButton);
                SDL_RenderPresent(renderer);
            }
        }
    }
}

void gameMenu(SDL_Window *window, SDL_Renderer *renderer, SDL_Event &e)
{
    SDL_Texture *main_background = loadTexture("Image/level_section.png", renderer);
    SDL_RenderCopy(renderer, main_background, NULL, NULL);
    loadFont("LEVEL", 70, 20, 150, 50, renderer);
    for(int i = 1; i <= 30; i++)
    {
        SDL_Texture *level_background = loadTexture("Image/level_background.png", renderer);
        SDL_Rect lvRect;
        if(i <= 10)
        {
            lvRect.x = 20+50*i;
            lvRect.y = 100;
        }
        else if(i <= 20)
        {
            lvRect.x = 20+50*(i-10);
            lvRect.y = 200;
        }
        else if(i <= 30)
        {
            lvRect.x = 20+50*(i-20);
            lvRect.y = 300;
        }
        lvRect.w = 40;
        lvRect.h = 40;
        SDL_RenderCopy(renderer, level_background, NULL, &lvRect);
        string s = to_string(i);
        loadFont(s ,lvRect.x+5, lvRect.y+5, 30, 30, renderer);
    }
    SDL_RenderPresent(renderer);
    while(true)
    {
        SDL_Delay(10);
        if ( SDL_WaitEvent(&e) == 0) continue;
        if (e.type == SDL_QUIT) quitSDL(window, renderer);
        if(e.type == SDL_MOUSEBUTTONDOWN)
        {
            for(int i = 1; i <= 30; i++)
            {
                SDL_Texture *level_background = loadTexture("Image/level_background.png", renderer);
                SDL_Rect lvRect;
                if(i <= 10)
                {
                    lvRect.x = 20+50*i;
                    lvRect.y = 100;
                }
                else if(i <= 20)
                {
                    lvRect.x = 20+50*(i-10);
                    lvRect.y = 200;
                }
                else if(i <= 30)
                {
                    lvRect.x = 20+50*(i-20);
                    lvRect.y = 300;
                }
                lvRect.w = 40;
                lvRect.h = 40;
                string s = to_string(i);
                if(e.button.x <= lvRect.x+lvRect.w & e.button.x >= lvRect.x && e.button.y <= lvRect.y+lvRect.h && e.button.y >= lvRect.y)
                {
                    gamePlay(window, renderer, e, s, tmp_map);
                    quitSDL(window, renderer);
                    break;
                }
            }
        }
    }
}

void loadFont(string s, int x, int y, int w, int h, SDL_Renderer *renderer)
{
    if(TTF_Init() < 0)
    {
        SDL_Log("%s", TTF_GetError());
        SDL_Quit();
    }

    TTF_Font *font = TTF_OpenFont("Font/Roboto-Bold.ttf", 30);
    SDL_Color color = {253,242,0};
    SDL_Surface *surface = TTF_RenderText_Solid(font, s.c_str(), color);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);

    SDL_Rect srcRest;
    SDL_Rect desRect = {x,y,w,h};
    TTF_SizeText(font, s.c_str(), &srcRest.w, &srcRest.h);
    srcRest.x = 0;
    srcRest.y = 100;
    SDL_RenderCopy(renderer, texture, NULL, &desRect);
    //SDL_RenderPresent(renderer);
}

void Option(int &option_is_on, SDL_Event &e, SDL_Window *window, SDL_Renderer *renderer, char (&tmp_map)[24][16])
{
        while(true)
        {
                SDL_Delay(10);
                if ( SDL_WaitEvent(&e) == 0) continue;
                if (e.type == SDL_QUIT) quitSDL(window, renderer);
                if(e.type == SDL_MOUSEBUTTONDOWN)
                {
                    if(e.button.button == SDL_BUTTON_LEFT)
                    {
                        if(e.button.x >= 212 && e.button.x <= 388 && e.button.y >= 122 && e.button.y <= 162)
                        {
                            //resume
                            break;
                        }
                        else if(e.button.x >= 212 && e.button.x <= 388 && e.button.y >= 181 && e.button.y <= 220)
                        {
                            //restart
                            gamePlay(window, renderer, e, "Restart", tmp_map);
                        }
                        else if(e.button.x >= 212 && e.button.x <= 388 && e.button.y >= 238 && e.button.y <= 277)
                        {
                            gameMenu(window, renderer, e);
                        }
                    }
                }
        }
        option_is_on++;
}
