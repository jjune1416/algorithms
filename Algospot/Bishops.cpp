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

void SetBishop(int Y, int X, int add)
{
    int _X = X - 1;
    int _Y = Y + 1;
    while(_X >= 0 && _Y < gridSize && grid[_Y][_X] != '*')
        grid[_Y++][_X--] += add;
    
    _X = X + 1;
    _Y = Y + 1;
    while(_X < gridSize && _Y < gridSize && grid[_Y][_X] != '*')
        grid[_Y++][_X++] += add;
}


int HowManyWays(int index)
{
    if(index == gridSize * gridSize)    return 0;
    int ret = HowManyWays(index + 1);
    
    int X = index % gridSize;
    int Y = index / gridSize;
    
    if(!grid[Y][X])
    {
        SetBishop(Y, X, 1);
        ret = std::max(ret, 1 + HowManyWays(index + 1));
        SetBishop(Y, X, -1);
    }
    
    return ret;
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
        for(int i = 0 ;i < gridSize ; i++)
            for(int j = 0 ; j< gridSize ;j++)
                grid[i][j] = (grid[i][j] == '*' ? '*' : 0);
        std::cout << HowManyWays(0) << std::endl;
    }
    return 0;
}
