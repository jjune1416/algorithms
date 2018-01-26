//
//  Quantization.cpp
//  https://algospot.com/judge/problem/read/QUANTIZE
//
//  Created by Ghost on 2018. 1. 26..
//  Copyright © 2018년 Ghost. All rights reserved.
//

#include <iostream>
#include <algorithm>

const int MAX_NUM = 100;
const int MAX_QUAN = 10;
const int INF = 98654321;

int numberCount;
int qntCount;
int numbers[MAX_NUM];

int memo[MAX_QUAN + 1][MAX_NUM + 1];

int Quantization(int numberIndex, int qntIndex)
{
    int& ret = memo[qntIndex][numberIndex];
    if(ret != -1) return ret;
    if(qntIndex == qntCount)   return ret = (numberIndex == numberCount) ? 0 : INF;
    if(numberIndex == numberCount) return ret = 0;

    ret = INF;
    int sum = 0;
    for(int i = numberIndex ; i < numberCount ; i++)
    {
        sum += numbers[i];
        int qnt = (float)sum / (float)(i - numberIndex + 1) + 0.5;
        
        int squareOfErrors = 0;
        for(int j = numberIndex ; j <= i ; j++)
            squareOfErrors += (numbers[j] - qnt) * (numbers[j] - qnt);
        
        ret = std::min(squareOfErrors + Quantization(i + 1, qntIndex + 1), ret);
    }
    return ret;
}

int main()
{
    int TC;
    std::cin >> TC;
    while(TC--)
    {
        std::cin >> numberCount >> qntCount;
        for(int i = 0 ; i < numberCount; i++)
            std::cin >> numbers[i];
        for(int i = 0 ; i <= qntCount ; i++)
            for(int j = 0 ; j <= numberCount ; j++)
                memo[i][j] = -1;
        std::sort(numbers, numbers + numberCount);
        std::cout << Quantization(0,0) << std::endl;
    }
    return 0;
}
