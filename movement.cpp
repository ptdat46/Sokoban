#include "movement.h"
#include<bits/stdc++.h>
using namespace std;

void moveLeft(obj& player, vector<obj> &arr_coin, vector<obj> &arr_box, char (&game_map)[24][16],
              deque<vector<vector<char>>> &undo_list, vector<vector<char>> &game_map_saved, vector<char> row)
{
    int num_box;
    bool check = true;
    if(game_map[player.x-1][player.y] == '#') check = false;
    if(game_map[player.x-1][player.y] == 'o' && (game_map[player.x-2][player.y] == '#' || game_map[player.x-2][player.y] == 'o' || game_map[player.x-2][player.y] == 's')) check = false;
    if(game_map[player.x-1][player.y] == 's' && (game_map[player.x-2][player.y] == '#' || game_map[player.x-2][player.y] == 'o' || game_map[player.x-2][player.y] == 's')) check = false;
    if(check)
    {
        saveMap(undo_list, game_map_saved, row, game_map);
        bool check_position_on_coin = false;
        for(int i = 0; i < 6; i++)
        {
            if(player.x == arr_coin[i].x && player.y == arr_coin[i].y)
            {
                check_position_on_coin = true;
            }
        }
        if(check_position_on_coin)
        {
            game_map[player.x][player.y] = 'v';
        }
        else
        {
            game_map[player.x][player.y] = '_';
        }
        if(game_map[player.x-1][player.y] == 'o' || game_map[player.x-1][player.y] == 's')
        {
            for(int i = 0; i < 6; i++)
            {
                if(player.x-1 == arr_box[i].x && player.y == arr_box[i].y)
                {
                    num_box = i;
                    break;
                }
            }
            for(int i = 0; i < 6; i++)
            {
                if(arr_box[num_box].x - 1 == arr_coin[i].x && arr_box[num_box].y == arr_coin[i].y)
                {
                    game_map[arr_box[num_box].x-1][arr_box[num_box].y] = 's';
                    break;
                }
                else
                {
                    game_map[arr_box[num_box].x-1][arr_box[num_box].y] = 'o';
                }
            }
            arr_box[num_box].x -= 1;
        }
        game_map[player.x-1][player.y] = 'x';
        player.x -= 1;
    }
};
void moveRight(obj& player, vector<obj> &arr_coin, vector<obj> &arr_box, char (&game_map)[24][16],
               deque<vector<vector<char>>> &undo_list, vector<vector<char>> &game_map_saved, vector<char> row)
{
    int num_box;
    bool check = true;
    if(game_map[player.x+1][player.y] == '#') check = false;
    if(game_map[player.x+1][player.y] == 'o' && (game_map[player.x+2][player.y] == '#' || game_map[player.x+2][player.y] == 'o' || game_map[player.x+2][player.y] == 's')) check = false;
    if(game_map[player.x+1][player.y] == 's' && (game_map[player.x+2][player.y] == '#' || game_map[player.x+2][player.y] == 'o' || game_map[player.x+2][player.y] == 's')) check = false;
    if(check)
    {
        saveMap(undo_list, game_map_saved, row, game_map);
        bool check_position_on_coin = false;
        for(int i = 0; i < 6; i++)
        {
            if(player.x == arr_coin[i].x && player.y == arr_coin[i].y)
            {
                check_position_on_coin = true;
            }
        }
        if(check_position_on_coin)
        {
            game_map[player.x][player.y] = 'v';
        }
        else
        {
            game_map[player.x][player.y] = '_';
        }
        if(game_map[player.x+1][player.y] == 'o' || game_map[player.x+1][player.y] == 's')
        {
            for(int i = 0; i < 6; i++)
            {
                if(player.x+1 == arr_box[i].x && player.y == arr_box[i].y)
                {
                    num_box = i;
                    break;
                }
            }
            for(int i = 0; i < 6; i++)
            {
                if(arr_box[num_box].x + 1 == arr_coin[i].x && arr_box[num_box].y == arr_coin[i].y)
                {
                    game_map[arr_box[num_box].x+1][arr_box[num_box].y] = 's';
                    break;
                }
                else
                {
                    game_map[arr_box[num_box].x+1][arr_box[num_box].y] = 'o';
                }
            }
            arr_box[num_box].x += 1;
        }
        game_map[player.x+1][player.y] = 'x';
        player.x += 1;
    }
}

void moveDown(obj& player, vector<obj> &arr_coin, vector<obj> &arr_box, char (&game_map)[24][16],
              deque<vector<vector<char>>> &undo_list, vector<vector<char>> &game_map_saved, vector<char> row)
{
    int num_box;
    bool check = true;
    if(game_map[player.x][player.y+1] == '#') check = false;
    if(game_map[player.x][player.y+1] == 'o' && (game_map[player.x][player.y+2] == '#' || game_map[player.x][player.y+2] == 'o' || game_map[player.x][player.y+2] == 's')) check = false;
    if(game_map[player.x][player.y+1] == 's' && (game_map[player.x][player.y+2] == '#' || game_map[player.x][player.y+2] == 'o' || game_map[player.x][player.y+2] == 's')) check = false;
    if(check)
    {
        saveMap(undo_list, game_map_saved, row, game_map);
        bool check_position_on_coin = false;
        for(int i = 0; i < 6; i++)
        {
            if(player.x == arr_coin[i].x && player.y == arr_coin[i].y)
            {
                check_position_on_coin = true;
            }
        }
        if(check_position_on_coin)
        {
            game_map[player.x][player.y] = 'v';
        }
        else
        {
            game_map[player.x][player.y] = '_';
        }
        if(game_map[player.x][player.y+1] == 'o' || game_map[player.x][player.y+1] == 's')
        {
            for(int i = 0; i < 6; i++)
            {
                if(player.x == arr_box[i].x && player.y + 1 == arr_box[i].y)
                {
                    num_box = i;
                    break;
                }
            }
            for(int i = 0; i < 6; i++)
            {
                if(arr_box[num_box].x == arr_coin[i].x && arr_box[num_box].y + 1 == arr_coin[i].y)
                {
                    game_map[arr_box[num_box].x][arr_box[num_box].y+1] = 's';
                    break;
                }
                else
                {
                    game_map[arr_box[num_box].x][arr_box[num_box].y+1] = 'o';
                }
            }
            arr_box[num_box].y += 1;
        }
        game_map[player.x][player.y+1] = 'x';
        player.y += 1;
    }
}

void moveUp(obj& player, vector<obj> &arr_coin, vector<obj> &arr_box, char (&game_map)[24][16],
            deque<vector<vector<char>>> &undo_list, vector<vector<char>> &game_map_saved, vector<char> row)
{
    int num_box;
    bool check = true;
    if(game_map[player.x][player.y-1] == '#') check = false;
    if(game_map[player.x][player.y-1] == 'o' && (game_map[player.x][player.y-2] == '#' || game_map[player.x][player.y-2] == 'o' || game_map[player.x][player.y-2] == 's')) check = false;
    if(game_map[player.x][player.y-1] == 's' && (game_map[player.x][player.y-2] == '#' || game_map[player.x][player.y-2] == 'o' || game_map[player.x][player.y-2] == 's')) check = false;
    if(check)
    {
        saveMap(undo_list, game_map_saved, row, game_map);
        bool check_position_on_coin = false;
        for(int i = 0; i < 6; i++)
        {
            if(player.x == arr_coin[i].x && player.y == arr_coin[i].y)
            {
                check_position_on_coin = true;
            }
        }
        if(check_position_on_coin)
        {
            game_map[player.x][player.y] = 'v';
        }
        else
        {
            game_map[player.x][player.y] = '_';
        }
        if(game_map[player.x][player.y-1] == 'o' || game_map[player.x][player.y-1] == 's')
        {
            for(int i = 0; i < 6; i++)
            {
                if(player.x == arr_box[i].x && player.y - 1 == arr_box[i].y)
                {
                    num_box = i;
                    break;
                }
            }
            for(int i = 0; i < 6; i++)
            {
                if(arr_box[num_box].x == arr_coin[i].x && arr_box[num_box].y - 1 == arr_coin[i].y)
                {
                    game_map[arr_box[num_box].x][arr_box[num_box].y-1] = 's';
                    break;
                }
                else
                {
                    game_map[arr_box[num_box].x][arr_box[num_box].y-1] = 'o';
                }
            }
            arr_box[num_box].y -= 1;
        }
        game_map[player.x][player.y-1] = 'x';
        player.y -= 1;
    }
}

void saveMap(deque<vector<vector<char>>> &undo_list, vector<vector<char>> &game_map_saved, vector<char> row, char (&game_map)[24][16])
{
    game_map_saved.clear();
    for(int j = 0; j < 16; j++)
    {
        row.clear();
        for(int i = 0; i < 24; i++)
        {
            row.push_back(game_map[i][j]);
        }
        game_map_saved.push_back(row);
    }
    if(undo_list.size() <= 3)
    {
        undo_list.push_back(game_map_saved);
    }
    else
    {
        undo_list.pop_front();
        undo_list.push_back(game_map_saved);
    };
}

