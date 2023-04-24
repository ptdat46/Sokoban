#include<bits/stdc++.h>
#include<SDL.h>
#include<SDL_image.h>
using namespace std;

void loadMap(char game_map[24][16], SDL_Renderer *renderer, bool &check_success, int music_is_pause, int option_is_on);
SDL_Texture* loadTexture(const char* filename, SDL_Renderer *renderer);


