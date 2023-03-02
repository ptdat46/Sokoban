#include <iostream>
#include<SDL.h>
#include<SDL_image.h>
/*Hàm báo lỗi*/
void logSDLError(std::ostream& os, const std::string &msg, bool fatal = false);
void logSDLError(std::ostream& os, const std::string &msg, bool fatal)
{
    os << msg << " Error: " << SDL_GetError() << std::endl;
    if (fatal) {
        SDL_Quit();
        exit(1);
    }
}

/*Hàm khởi tạo*/
const int window_width = 550;
const int window_height = 550;
const int border = 50;
const int pixel = 50;
const std::string window_title = "Game project";

void initSDL(SDL_Window* &window, SDL_Renderer* &renderer);
void initSDL(SDL_Window* &window, SDL_Renderer* &renderer) {
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        logSDLError(std::cout, "SDL_Init", true);
    }
    window = SDL_CreateWindow(window_title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                              window_width, window_height, SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        logSDLError(std::cout, "Create window", true);
    }
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr) {
        logSDLError(std::cout, "create renderer", true);
    }
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    SDL_RenderSetLogicalSize(renderer, window_width, window_height);
}

/*Hàm quit */
void quitSDL(SDL_Window* window, SDL_Renderer* renderer);
void quitSDL(SDL_Window* window, SDL_Renderer* renderer) {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

/*Đợi nhấn phím*/
void waitUntilKeyPressed();
void waitUntilKeyPressed() {
    SDL_Event event;
    while (true) {
        if (SDL_WaitEvent(&event) != 0 && event.type == SDL_QUIT) {
            return;
        }
        SDL_Delay(100);
    }
}

/*Hàm di chuyển Move functions*/
/*void up() {
    player_pos.y -= pixel;
}

void down() {
    player_pos.y += pixel;
}

void right() {
    player_pos.x += pixel;
}

void left() {
    player_pos.x -= pixel;
}
*/

/*Hàm load ảnh*/
SDL_Texture* loadTexture(std::string path, SDL_Renderer* renderer) {
    SDL_Texture* newTexture = nullptr;
    SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
    if (loadedSurface == nullptr)
    {
        std::cout << "Unable to load image " << path << " SDL_Image Error " << IMG_GetError() << std::endl;
    }
    else
    {
        newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
        if( newTexture == nullptr )
        {
            std::cout << "Unable to create texture from " << path << " SDL Error " << SDL_GetError() << std::endl;
        }
        SDL_FreeSurface(loadedSurface);
    }
}

int main(int argc, char* argv[])
{
    SDL_Window* window;
    SDL_Renderer* renderer;
    initSDL(window, renderer);
    /*vẽ ở đây*/
    SDL_RenderClear(renderer);
    /*Màu nền Background Color*/
    SDL_SetRenderDrawColor(renderer, 60,69,86,255);
    SDL_RenderClear(renderer);
    /*Không gian trò chơi Game Space*/
    SDL_SetRenderDrawColor(renderer, 255,255,255,255);
    SDL_Rect filled_rect_2;
    filled_rect_2.x = border;
    filled_rect_2.y = border;
    filled_rect_2.w = window_width-2*border;
    filled_rect_2.h = window_height-2*border;
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    SDL_RenderFillRect(renderer, &filled_rect_2);
    SDL_RenderPresent(renderer);
    /*Game loop*/
    bool running = true;
    bool game_map[9][9];
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            game_map[i][j] = true;
        }
    }
    while(running) {
        /*Game map*/
        /*Level 1*/
        for(int i = 0; i < 9; i++)
        {
            if(i == 0 || i == 8) {
                for(int j = 0; j < 9; j++) {
                    game_map[i][j] = false;
                }
            }
            if(i == 1 || i == 3) {
                game_map[i][0] = false;
                game_map[i][1] = false;
                game_map[i][7] = false;
                game_map[i][8] = false;
            }
            if(i == 2) {
                game_map[i][0] = false;
                game_map[i][1] = false;
                game_map[i][3] = false;
                game_map[i][6] = false;
                game_map[i][7] = false;
                game_map[i][8] = false;
            }
            if( i == 4) {
                game_map[i][7] = false;
                game_map[i][8] = false;
            }
            if(i == 5) {
                game_map[i][6] = false;
                game_map[i][7] = false;
                game_map[i][8] = false;
            }
            if(i == 6 || i == 7) {
                game_map[i][0] = false;
                game_map[i][1] = false;
                game_map[i][6] = false;
                game_map[i][7] = false;
                game_map[i][8] = false;
            }
        }
        if(SDL_QUIT) {
            running = false;
        }
    }
    /*----------------------------------------------------------------------*/
    for(int j = 0; j < 9; j++) {
        for(int i = 0; i < 9; i++) {

        }
    }
    /*hết*/
    waitUntilKeyPressed();
    quitSDL(window, renderer);
    return 0;
}
