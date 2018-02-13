//
//  Sushi.cpp
//  https://algospot.com/judge/problem/read/SUSHI
//
//  Created by Ghost on 2018. 2. 11..
//  Copyright © 2018년 Ghost. All rights reserved.
//

#include <cstring>
#include <iostream>
#include <algorithm>

const int MAX_SUSHI = 20;
const int SIZE_MEMO = 201;
int memo[SIZE_MEMO];
int sushiSize;
int price[MAX_SUSHI];
int priority[MAX_SUSHI];

int GetMaxPriority(int budgit)
{
    memo[0] = 0;
    for(int i = 1;i <= budgit ;i++)
    {
        int max = 0;
        for(int sushi = 0 ;sushi < sushiSize ;sushi ++)
        {
            if(price[sushi] > i) continue;
            max = std::max(max, priority[sushi] + memo[(i - price[sushi]) % SIZE_MEMO]);
        }
        memo[i % SIZE_MEMO] = max;
    }
    return memo[budgit % SIZE_MEMO];
}

int main()
{
    int TC;
    std::cin >> TC;
    while(TC--)
    {
        int budgit;
        std::cin >> sushiSize >> budgit;

        for(int i = 0 ;i < sushiSize ; i++)
            std::cin >>  price[i] >> priority[i];
        budgit /= 100;
        for(int i = 0 ;i < sushiSize ; i++)
            price[i] /= 100;
        std::cout << GetMaxPriority(budgit) << std::endl;
    }
    return 0;
}
