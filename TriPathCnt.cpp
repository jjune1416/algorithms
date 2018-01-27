//
//  TriPathCnt.cpp
//  TriPathCnt
//
//  Created by Ghost on 2018. 1. 27..
//  Copyright © 2018년 Ghost. All rights reserved.
//

#include <iostream>
#include <algorithm>

const int MAX = 100;

int height;
int triangle[MAX][MAX];
int maxMemo[MAX][MAX];
int pathMemo[MAX][MAX];

int TrianglePath(int y, int x)
{
    int& ret = maxMemo[y][x];
    if(ret != -1) return ret;
    if(y == height - 1) return ret = triangle[y][x];
    return ret = triangle[y][x] + std::max(TrianglePath(y+1, x), TrianglePath(y+1, x+1));
}

int TriPathCnt(int y, int x)
{
    int& ret = pathMemo[y][x];
    if(ret != -1) return ret;
    if(y == height - 1) return ret = 1;
    
    ret = 0;
    int max = std::max(TrianglePath(y+1,x),TrianglePath(y+1,x+1));
    for(int i = 0 ; i <= 1; i++)
        if(max == TrianglePath(y+1,x+i))
            ret += TriPathCnt(y+1, x+i);
    return ret;
}

int main()
{
    int TC;
    std::cin >> TC;;
    while(TC--)
    {
        std::cin >> height;
        for(int i = 0 ; i < height; i++)
            for(int j = 0 ; j <= i ; j++)
                std::cin >> triangle[i][j], pathMemo[i][j] = maxMemo[i][j] = -1;
        std::cout << TriPathCnt(0,0) << std::endl;
    }
    return 0;
}
