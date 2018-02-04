//
//  Bishops.cpp
//  Bishops
//
//  Created by Ghost on 2018. 2. 5..
//  Copyright © 2018년 Ghost. All rights reserved.
//

#include <iostream>

const int MAX_GRID = 9;
char grid[MAX_GRID][MAX_GRID];

int gridSize;
int availableSpace;
int maxBishop;

int SetBishop(int Y, int X, int add)
{
    int ret = 0;
    
    int _X = X - 1;
    int _Y = Y + 1;
    while(_X >= 0 && _Y < gridSize && grid[_Y][_X] != '*')
    {
        ret += !grid[_Y][_X];
        grid[_Y++][_X--] += add;
    }
    
    _X = X + 1;
    _Y = Y + 1;
    while(_X < gridSize && _Y < gridSize && grid[_Y][_X] != '*')
    {
        ret += !grid[_Y][_X];
        grid[_Y++][_X++] += add;
    }
    return ret;
}

void HowManyWays(int index, int bishopCount)
{
    if(index == gridSize * gridSize)
    {
        maxBishop = std::max(bishopCount, maxBishop);
        return;
    }
    if(bishopCount + availableSpace <= maxBishop)
        return;
    
    HowManyWays(index + 1, bishopCount);
    
    int X = index % gridSize;
    int Y = index / gridSize;
    
    if(!grid[Y][X])
    {
        int disabledCount = SetBishop(Y, X, 1);
        availableSpace -= disabledCount;
        HowManyWays(index + 1, bishopCount + 1);
        SetBishop(Y, X, -1);
        availableSpace += disabledCount;
    }
}

int main()
{
    int TC;
    std::cin >> TC;
    while(TC--)
    {
        std::cin >> gridSize;
        for(int i = 0 ;i < gridSize ; i++)
            std::cin >> grid[i];
        availableSpace = maxBishop = 0;
        for(int i = 0 ;i < gridSize ; i++)
        {
            for(int j = 0 ; j< gridSize ;j++)
            {
                if(grid[i][j] == '.')
                {
                    availableSpace++;
                    grid[i][j] = 0;
                }
            }
        }
        HowManyWays(0, 0);
        std::cout << maxBishop << std::endl;
    }
    return 0;
}
