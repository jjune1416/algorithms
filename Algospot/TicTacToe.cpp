//
//  TicTacToe.cpp
//  https://algospot.com/judge/problem/read/TICTACTOE
//
//  Created by Ghost on 2018. 2. 11..
//  Copyright © 2018년 Ghost. All rights reserved.
//

#include <iostream>
#include <cstring>

const int GRID_SIZE = 3;
char grid[GRID_SIZE][GRID_SIZE+1];

char memo[20000];

char WhosTurn()
{
    int ret = 0;
    for(int i = 0 ; i < GRID_SIZE; i++)
    {
        for(int j = 0 ;j <GRID_SIZE ; j++)
        {
            ret += grid[i][j] == 'x';
            ret -= grid[i][j] == 'o';
        }
    }
    return ret ? 'o' : 'x';
}

int EmptyCellCount()
{
    int ret = 0;
    for(int i = 0 ; i < GRID_SIZE; i++)
        for(int j = 0 ;j <GRID_SIZE ; j++)
            ret += grid[i][j] == '.';
    return ret;
}

char Winner()
{
    for(int i = 0 ;i < 3; i++)
        if(grid[i][0] != '.' && (grid[i][0] == grid[i][1]) && (grid[i][0] == grid[i][2]))
            return grid[i][0];
    for(int i = 0 ;i < 3; i++)
        if(grid[0][i] != '.' && (grid[0][i] == grid[1][i]) && (grid[0][i] == grid[2][i]))
            return grid[0][i];
    if(grid[0][0] != '.' && (grid[0][0] == grid[1][1]) && (grid[0][0] == grid[2][2]))
        return grid[0][0];
    if(grid[0][2] != '.' && (grid[0][2] == grid[1][1]) && (grid[0][2] == grid[2][0]))
        return grid[0][2];
    return '.';
}

int GetMemoIndex()
{
    int ret = 0;
    for(int i = 0 ; i < 9 ;i++)
    {
        ret *= 3;
        int x = i % 3, y = i / 3;
        if(grid[y][x] == 'o')       ret += 2;
        else if(grid[y][x] == 'x')  ret += 1;
    }
    return ret;
}

char WhoIsWinner(int emptyCount, char turn)
{
    char& ret = memo[GetMemoIndex()];
    if(ret != 0)    return ret;
    
    char winner = Winner();
    if(winner != '.')   return ret = winner;
    if(emptyCount == 0)  return ret = '.';
    
    ret = '.';
    int opponentWinCount = 0;
    char opponent = ((turn == 'o') ? 'x' : 'o');
    for(int i = 0 ;i < 9; i++)
    {
        int x = i % 3, y = i / 3;
        if(grid[y][x] != '.') continue;
        
        grid[y][x] = turn;
        char winner = WhoIsWinner(emptyCount - 1, opponent);
        grid[y][x] = '.';
        
        if(winner == turn)          return ret = turn;
        else if(winner == opponent) opponentWinCount++;
    }
    return ret = (opponentWinCount == emptyCount ? ret = opponent : ret);
}

int main()
{
    int TC;
    std::cin >> TC;
    memset(memo, 0 , sizeof(memo));
    while(TC--)
    {
        for(int i = 0 ;i < GRID_SIZE ; i++)
            std::cin >> grid[i];
        char turn = WhosTurn();
        int emptyCount = EmptyCellCount();
        if(WhoIsWinner(emptyCount, turn) == '.') std::cout << "TIE" << std::endl;
        else                                     std::cout << WhoIsWinner(emptyCount, turn) << std::endl;
    }
    return 0;
}
