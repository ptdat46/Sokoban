#include<bits/stdc++.h>

using namespace std;

int main()
{
    bool game_map[9][9];
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            game_map[i][j] = true;
        }
    }
    /*Unchange pictures*/
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
    for(int j = 0; j < 9; j++)
    {
        for(int i = 0; i < 9; i++)
        {
            if(game_map[i][j] == false)
            {
                cout << "*";
            }
            else {
                cout << " ";
            }
        }
        cout << endl;
    }
}
