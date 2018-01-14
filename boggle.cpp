//
//  boggle.cpp
//  algorithms
//
//  Created by Ghost on 2018. 1. 14..
//  Copyright © 2018년 Ghost. All rights reserved.
//

#include <stdio.h>
#include <iostream>

#define GRID_SIZE   5
#define MAX_WORD_SIZE 10

bool gridVisited[GRID_SIZE][GRID_SIZE][MAX_WORD_SIZE + 1];

char grid[GRID_SIZE][GRID_SIZE+1];
char word[MAX_WORD_SIZE + 1];

const int dx[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
const int dy[8] = {-1, -1, -1, 0, 1, 1, 1, 0};

void clearMemo()
{
    for(int i = 0 ;i <GRID_SIZE; i++)
        for(int j = 0 ;j < GRID_SIZE;j++)
            for(int k = 0 ;k<=MAX_WORD_SIZE;k++)
                gridVisited[i][j][k] = false;
}

inline int isOutOfRange(int x, int y)
{
    return (x < 0) || (y < 0) || (x >= GRID_SIZE) || (y >= GRID_SIZE);
}

int findWord(int depth, char* word, int x, int y)
{
    if(word[depth] == 0)    return true;
    if(isOutOfRange(x, y)) return false;
    
    if(gridVisited[y][x][depth])    return false;
    gridVisited[y][x][depth] = true;
    
    if(grid[y][x] != word[depth])   return false;
    
    for(int i = 0; i < 8; i++)
    {
        if(findWord(depth+1, word, x + dx[i], y + dy[i])) return true;
    }
    
    return false;
}

int main()
{
    //freopen("tc.txt", "r", stdin);
    int TC;
    scanf("%d", &TC);
    while(TC--)
    {
        int numWord;
        for(int i = 0; i < GRID_SIZE ; i++)
        {
            scanf("%s", grid[i]);
        }
        scanf("%d", &numWord);
        for(int i = 0 ;i < numWord; i++)
        {
            clearMemo();
            bool possible = false;
            scanf("%s", word);
            for(int point = 0 ; point < 25; point++)
            {
                int y = point / 5;
                int x = point % 5;
                if(findWord(0, word, x, y))
                {
                    possible = true;
                    break;
                }
            }
            printf("%s %s\n", word, (possible ? "YES" : "NO"));
        }
    }
    return 0;
}
