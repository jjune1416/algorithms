//
//  NumberGame.cpp
//  https://algospot.com/judge/problem/read/NUMBERGAME
//
//  Created by Ghost on 2018. 2. 11..
//  Copyright © 2018년 Ghost. All rights reserved.
//

#include <iostream>
#include <algorithm>

const int MAX_COUNT = 50;
const int INF = -1987654321;

int countNumber;
int number[MAX_COUNT];

int memo[MAX_COUNT][MAX_COUNT];

int GetMaxDiff(int left, int right)
{
    if(left > right)    return 0;

    int& ret = memo[left][right];
    if(ret != INF)  return ret;
    
    if(right - left >= 1)
    {
        ret = std::max(ret, -GetMaxDiff(left+2, right));
        ret = std::max(ret, -GetMaxDiff(left, right-2));
    }
    ret = std::max(ret, number[left]-GetMaxDiff(left+1, right));
    ret = std::max(ret, number[right]-GetMaxDiff(left, right-1));
    return ret;
}

int main()
{
    int TC;
    std::cin >> TC;
    while(TC--)
    {
        std::cin >> countNumber;
        for(int i = 0 ; i < countNumber ;i++)
            std::cin >> number[i];
        for(int i = 0; i < countNumber ; i++)
            for(int j = 0; j <countNumber ;j++)
                memo[i][j] = INF;
        std::cout << GetMaxDiff(0, countNumber-1) << std::endl;
    }
    return 0;
}
