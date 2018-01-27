//
//  TILING2.cpp
//  https://algospot.com/judge/problem/read/TILING2
//
//  Created by Ghost on 2018. 1. 27..
//  Copyright © 2018년 Ghost. All rights reserved.
//

#include <iostream>

const int MAX = 101;
const int MOD = 1000000007;
int way[MAX];

void preCalc()
{
    way[0] = way[1] = 1;
    for(int i = 2; i < MAX; i++)
        way[i] = (way[i-1] + way[i-2]) % MOD;
}

int main()
{
    int TC;
    std::cin >> TC;
    preCalc();
    while(TC--)
    {
        int tileCount;
        std::cin >> tileCount;
        std::cout << way[tileCount] << std::endl;
    }
    
    return 0;
}
