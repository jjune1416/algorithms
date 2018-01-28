//
//  LIS.cpp
//  https://algospot.com/judge/problem/read/LIS
//
//  Created by Ghost on 2018. 1. 23..
//  Copyright © 2018년 Ghost. All rights reserved.
//

#include <iostream>
#include <algorithm>

const int MAX_LEN = 500;

int length;
int arr[MAX_LEN + 1];
int retMemo[MAX_LEN + 1];

int LIS(int pivot)
{
    int& ret = retMemo[pivot];
    if(ret != -1) return ret;
    int max = 0;
    for(int i = pivot + 1 ; i <= length ; i++)
        if(arr[i] > arr[pivot])
            max = std::max(LIS(i), max);
    return ret = max + 1;
}

int main()
{
    int TC;
    std::cin >> TC;
    while(TC--)
    {
        std::cin >> length;
        arr[0] = retMemo[0] =  -1;
        for(int i = 1 ;i <= length; i++)
            std::cin >> arr[i], retMemo[i] = -1;
        std::cout << LIS(0) - 1 << std::endl;
    }
    return 0;
}
