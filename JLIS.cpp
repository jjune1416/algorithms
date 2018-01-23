//
//  JLIS.cpp
//  https://algospot.com/judge/problem/read/JLIS
//
//  Created by Ghost on 2018. 1. 23..
//  Copyright © 2018년 Ghost. All rights reserved.
//

#include <iostream>
#include <algorithm>

const int MAX_LEN = 101;

int length1;
int length2;
long long int arr1[MAX_LEN];
long long int arr2[MAX_LEN];
int retMemo[MAX_LEN][MAX_LEN];

int JLIS(int pivot1, int pivot2)
{
    int& ret = retMemo[pivot1][pivot2];
    if(ret != -1) return ret;
    
    long long int lastNum = std::max(arr1[pivot1], arr2[pivot2]);
    
    ret = 0;
    for(int i = pivot1 + 1 ; i <= length1 ; i++)
        if(arr1[i] > lastNum)
            ret = std::max(JLIS(i, pivot2) + 1, ret);
    for(int i = pivot2 + 1 ; i <= length2 ; i++)
        if(arr2[i] > lastNum)
            ret = std::max(JLIS(pivot1, i) + 1, ret);
    return ret;
}

int main()
{
    int TC;
    std::cin >> TC;
    while(TC--)
    {
        std::cin >> length1;
        std::cin >> length2;
        for(int i = 1 ;i <= length1; i++)
            std::cin >> arr1[i];
        for(int i = 1 ;i <= length2; i++)
            std::cin >> arr2[i];
        for(int i = 0 ;i <= length1; i++)
            for(int j = 0; j <= length2; j++)
                retMemo[i][j] = -1;
        arr1[0] = arr2[0] = -198765432100L;
        std::cout << JLIS(0, 0) << std::endl;
    }
    return 0;
}
