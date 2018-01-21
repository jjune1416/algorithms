//
//  jump_game.cpp
//  https://algospot.com/judge/problem/read/JUMPGAME
//
//  Created by Ghost on 2018. 1. 21..
//  Copyright © 2018년 Ghost. All rights reserved.
//

#include <iostream>
#include <string.h>

const int MAX_GRID = 100;
int grid[MAX_GRID][MAX_GRID];
bool visit[MAX_GRID][MAX_GRID];
int width;

int dx[2] = {1, 0};
int dy[2] = {0, 1};

void Input()
{
    std::cin >> width;
    for(int i = 0;i < width; i++)
        for(int j = 0 ;j <width; j++)
            std::cin >> grid[i][j];
     memset(visit, false, MAX_GRID * MAX_GRID);
}

inline bool IsRange(int y, int x)
{
    return (x >= 0 && y >= 0 && x < width && y < width);
}

bool Solve(int y, int x)
{
    if(!IsRange(y,x))   return false;
    if(visit[y][x])     return false;
    visit[y][x] = true;
    
    if(y == width - 1 && x == width - 1) return true;
    
    for(int i = 0; i < 2; i ++)
    {
        int nextX = x + dx[i] * grid[y][x];
        int nextY = y + dy[i] * grid[y][x];
        if(Solve(nextY, nextX)) return true;
    }
    
    return false;
}

int main()
{
    int TC;
    std::cin >> TC;
    while(TC--)
    {
        Input();
        std::cout << (Solve(0,0) ? "YES" : "NO") << std::endl;
    }
    return 0;
}
