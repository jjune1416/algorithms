//
//  TrianglePath.cpp
//  https://algospot.com/judge/problem/read/TRIANGLEPATH
//
//  Created by Ghost on 2018. 1. 23..
//  Copyright © 2018년 Ghost. All rights reserved.
//

#include <iostream>
#include <algorithm>

const int MAX_DEPTH = 100;

int size;
int triangle[MAX_DEPTH][MAX_DEPTH];
int retMemo[MAX_DEPTH][MAX_DEPTH];

int TrianglePath(int y, int x)
{
    int& ret = retMemo[y][x];
    if(ret != -1) return ret;
    if(y == size - 1) return ret = triangle[y][x];
    return ret = triangle[y][x] + std::max(TrianglePath(y+1, x), TrianglePath(y+1, x+1));
}

int main()
{
    int TC;
    std::cin >> TC;
    while(TC--)
    {
        std::cin >> size;
        for(int i = 0 ;i < size; i++)
            for(int j = 0 ; j <= i ; j++)
                std::cin >> triangle[i][j], retMemo[i][j] = -1;
        std::cout << TrianglePath(0,0) << std::endl;
    }
    return 0;
}
