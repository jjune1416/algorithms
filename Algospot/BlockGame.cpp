//
//  BlockGame.cpp
//  https://algospot.com/judge/problem/read/BLOCKGAME
//
//  Created by Ghost on 2018. 2. 11..
//  Copyright © 2018년 Ghost. All rights reserved.
//

#include <iostream>
#include <cstring>

const int GRID_SIZE = 5;

char grid[GRID_SIZE][GRID_SIZE+1];
char memo[1<<25];

int cover[6][3][2] = {{{0,0}, {1,0}, {0,1}},
                        {{0,0},{0,1},{1,1}},
                        {{1,0},{0,1},{1,1}},
                        {{0,0},{1,0},{1,1}},
                        {{0,0},{0,0},{1,0}},
                        {{0,0},{0,0},{0,1}}};

inline int GetIndex()
{
    int ret = 0;
    for(int i = 0 ;i < 5; i++)
        for(int j = 0 ;j < 5; j++)
            ret = ret * 2 + (grid[i][j] == '.');
    return ret;
}

inline bool IsFillable(int y, int x, int coverType)
{
    for(int i = 0 ;i < 3; i++)
    {
        int _y = y + cover[coverType][i][0];
        int _x = x + cover[coverType][i][1];
        if(_y >= 5 || _x >= 5 || grid[_y][_x] == '#')
            return false;
    }
    return true;
}

inline void FillCoverWith(int y, int x, int coverType, char content)
{
    for(int i = 0 ;i < 3; i++)
        grid[y + cover[coverType][i][0]][x + cover[coverType][i][1]] = content;
}

char IsWinnable()
{
    char& ret = memo[GetIndex()];
    if(ret != -1)   return ret;
    
    for(int y = 0 ; y < 5; y++)
    {
        for(int x = 0 ; x < 5 ; x++)
        {
            for(int type = 0 ;type < 6; type++)
            {
                if(IsFillable(y,x,type))
                {
                    FillCoverWith(y,x,type,'#');
                    char winnable = IsWinnable();
                    FillCoverWith(y,x,type,'.');
                    if(!winnable)   return ret = 1;
                }
            }
        }
    }
    return ret = 0;
}

int main()
{
    int TC;
    std::cin >> TC;
    memset(memo, -1, sizeof(memo));
    while(TC--)
    {
        for(int i = 0; i< GRID_SIZE;i++)
            std::cin >> grid[i];
        std::cout << (IsWinnable() == 1 ? "WINNING" : "LOSING") << std::endl;
    }
    return 0;
}
