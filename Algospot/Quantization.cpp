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
int sums[MAX_NUM];
int squares[MAX_NUM];
int memo[MAX_QUAN + 1][MAX_NUM + 1];

void PreCalc()
{
    for(int i = 0 ; i <= qntCount ; i++)
        for(int j = 0 ; j <= numberCount ; j++)
            memo[i][j] = -1;
    std::sort(numbers, numbers + numberCount);
    sums[0] = numbers[0];
    for(int i = 1 ;i < numberCount ;i++)
        sums[i] = sums[i-1] + numbers[i];
    squares[0] = numbers[0] * numbers[0];
    for(int i = 1 ; i < numberCount; i++)
        squares[i] = squares[i-1] + numbers[i] * numbers[i];
}

int GetMinError(int i, int j)
{
    int sum = sums[j] - ((i==0) ? 0 : sums[i-1]);
    int square = squares[j] - ((i==0) ? 0 : squares[i-1]);
    int mean = (float)sum / (j - i + 1) + 0.5;
    return square - 2 * sum * mean + mean * mean * (j - i + 1);
}

int Quantization(int numberIndex, int qntIndex)
{
    int& ret = memo[qntIndex][numberIndex];
    if(ret != -1) return ret;
    if(qntIndex == qntCount)   return ret = (numberIndex == numberCount) ? 0 : INF;
    if(numberIndex == numberCount) return ret = 0;

    ret = INF;
    for(int i = numberIndex ; i < numberCount ; i++)
        ret = std::min(GetMinError(numberIndex, i) + Quantization(i + 1, qntIndex + 1), ret);
    
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
        PreCalc();
        std::cout << Quantization(0,0) << std::endl;
    }
    return 0;
}
