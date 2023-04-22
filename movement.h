#include<bits/stdc++.h>
using namespace std;
struct obj
{
    int x;
    int y;
    char z;
};

void moveLeft(obj& player, vector<obj> &arr_coin, vector<obj> &arr_box, char (&game_map)[24][16],
              deque<vector<vector<char>>> &undo_list, vector<vector<char>> &game_map_saved, vector<char> row);
void moveRight(obj& player, vector<obj> &arr_coin, vector<obj> &arr_box, char (&game_map)[24][16],
               deque<vector<vector<char>>> &undo_list, vector<vector<char>> &game_map_saved, vector<char> row);
void moveDown(obj& player, vector<obj> &arr_coin, vector<obj> &arr_box, char (&game_map)[24][16],
              deque<vector<vector<char>>> &undo_list, vector<vector<char>> &game_map_saved, vector<char> row);
void moveUp(obj& player, vector<obj> &arr_coin, vector<obj> &arr_box, char (&game_map)[24][16],
            deque<vector<vector<char>>> &undo_list, vector<vector<char>> &game_map_saved, vector<char> row);
void saveMap(deque<vector<vector<char>>> &undo_list, vector<vector<char>> &game_map_saved, vector<char> row, char (&game_map)[24][16]);
