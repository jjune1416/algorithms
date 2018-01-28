//
//  BoardCover.cpp
//  https://algospot.com/judge/problem/read/BOARDCOVER
//
//  Created by Ghost on 2018. 1. 14..
//  Copyright © 2018년 Ghost. All rights reserved.
//

#include <stdio.h>
#define MAX_GRID 20

char grid[MAX_GRID][MAX_GRID + 1];
int H, W, coverNeeded;
int cover[4][3][2] = {
    {{0,0}, {0,1}, {1,1}},
    {{0,0}, {1,0}, {1,-1}},
    {{0,0}, {1,1}, {1,0}},
    {{0,0}, {0,1}, {1,0}}};

const int indexX = 1;
const int indexY = 0;

inline int getNextX(int x, int y)
{
    return ++x % W;
}
inline int getNextY(int x, int y)
{
    return y + (++x / W );
}

bool isPossibleCover(int x, int y, int coverType)
{
    for(int i= 0 ;i <3; i++)
    {
        int targetX = x + cover[coverType][i][indexX];
        int targetY = y + cover[coverType][i][indexY];
        
        if(targetX < 0 || targetX >= W) return false;
        if(targetY < 0 || targetY >= H) return false;
        if(grid[targetY][targetX] == '#')    return false;
    }
    return true;
}

inline void coverTiles(int x, int y, int coverType)
{
    for(int i= 0 ;i <3; i++)
    {
        int targetX = x + cover[coverType][i][indexX];
        int targetY = y + cover[coverType][i][indexY];
        grid[targetY][targetX] = '#';
    }
}

inline void unCoverTiles(int x, int y, int coverType)
{
    for(int i= 0 ;i <3; i++)
    {
        int targetX = x + cover[coverType][i][indexX];
        int targetY = y + cover[coverType][i][indexY];
        grid[targetY][targetX] = '.';
    }
}

int howManyAnswerDFS(int x, int y, int coverCount)
{
    if(coverNeeded % 3)             return 0;
    if(coverCount == coverNeeded)   return 1;
    if(y == H)                      return 0;
    int nextX = getNextX(x, y);
    int nextY = getNextY(x, y);
    
    if(grid[y][x] == '#') return howManyAnswerDFS(nextX, nextY, coverCount);
    
    int ans = 0;
    for(int i= 0 ;i < 4; i++)
    {
        if(!isPossibleCover(x, y, i))   continue;
        coverTiles(x, y, i);
        ans += howManyAnswerDFS(nextX, nextY, coverCount + 3);
        unCoverTiles(x, y, i);
    }
    
    return ans;
}

int main()
{
    int TC;
    scanf("%d", &TC);
    while(TC--)
    {
        scanf("%d %d", &H, &W);
        for(int i= 0 ;i < H; i++)   scanf("%s", grid[i]);
        
        coverNeeded = 0;
        for(int i = 0 ; i < H; i++)
            for(int j = 0 ;j < W ; j++)
                coverNeeded += (grid[i][j] == '.');
        
        printf("%d\n", howManyAnswerDFS(0, 0, 0));
    }
    return 0;
}
