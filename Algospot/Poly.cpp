//
//  Poly.cpp
//  https://algospot.com/judge/problem/read/POLY
//
//  Created by Ghost on 2018. 1. 27..
//  Copyright © 2018년 Ghost. All rights reserved.
//

#include <iostream>

const int MOD = 10000000;
const int MAX = 101;
int memo[MAX][MAX];

int GetPolyCases(int curWidth, int leftSquareCnt)
{
    int& ret = memo[curWidth][leftSquareCnt];
    if(ret != -1)   return ret;
    
    if(leftSquareCnt == 0) return ret = 1;
    
    ret = 0 ;
    for(int nextWidth = 1;  nextWidth <= leftSquareCnt ; nextWidth++)
        ret = (ret + (nextWidth + curWidth - 1) * GetPolyCases(nextWidth, leftSquareCnt - nextWidth)) % MOD;
    return ret;
}

int main()
{
    int TC;
    std::cin >> TC;
    while(TC--)
    {
        int tileCount;
        std::cin >> tileCount;
        for(int i = 0 ;i <= tileCount; i++)
            for(int j = 0 ; j<= tileCount ;j++)
                memo[i][j] = -1;
        int totalCount = 0;
        for(int width = 1 ;width <= tileCount ; width++)
            totalCount = (totalCount + GetPolyCases(width, tileCount - width)) % MOD;
        std::cout << totalCount << std::endl;
        
    }
    return 0;
}
