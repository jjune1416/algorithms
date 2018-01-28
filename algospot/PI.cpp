//
//  PI.cpp
//  https://algospot.com/judge/problem/read/PI
//
//  Created by Ghost on 2018. 1. 24..
//  Copyright © 2018년 Ghost. All rights reserved.
//

#include <iostream>
#include <algorithm>

const int MAX = 10001;
const int INF = 400000;
int length;
char pi[MAX];
int minMemo[MAX];

int LocalDifficult(int pivot, int len)
{
    bool success;
    
    success = true;
    for(int i = 1 ; i < len ; i++)
        if(pi[pivot + i] != pi[pivot + i - 1])
            success = false;
    if(success) return 1;
    
    success = true;
    for(int i = 1 ; i < len ; i++)
        if(pi[pivot + i] - pi[pivot + i - 1] != 1)
            success = false;
    if(success) return 2;
    
    success = true;
    for(int i = 1 ; i < len ; i++)
        if(pi[pivot + i] - pi[pivot + i - 1] != -1)
            success = false;
    if(success) return 2;
    
    success = true;
    for(int i = 2 ; i < len ; i++)
        if(pi[pivot + i] != pi[pivot + i - 2])
            success = false;
    if(success) return 4;
    
    success = true;
    for(int i = 2 ; i < len ; i++)
        if(pi[pivot + i] - pi[pivot + i - 1] != pi[pivot + i - 1] - pi[pivot + i - 2])
            success = false;
    if(success) return 5;
    
    return 10;
}

int GlobalDifficult(int pivot)
{
    int& ret = minMemo[pivot];
    if(ret != -1) return ret;
    
    if (length == pivot)
        return ret = 0;
    
    ret = INF;
    for(int i = 3; i <= 5; i++)
        if(pivot + i <= length)
            ret = std::min(LocalDifficult(pivot, i) + GlobalDifficult(pivot + i), ret);
    return ret;
}

int main()
{
    int TC;
    std::cin >> TC;
    while(TC--)
    {
        std::cin >> pi;
        for(length = 0 ; pi[length] ; length++);
        for(int i = 0 ;i <= length; i++)
            minMemo[i] = -1;
        std::cout << GlobalDifficult(0) << std::endl;
    }
    return 0;
}
