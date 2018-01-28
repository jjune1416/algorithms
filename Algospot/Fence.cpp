//
//  fence.cpp
//  https://algospot.com/judge/problem/read/FENCE
//
//  Created by Ghost on 2018. 1. 17..
//  Copyright © 2018년 Ghost. All rights reserved.
//

#include <iostream>
#include <algorithm>
#define MAX_FENCE 20000

int fenceCount;
int fence[20000];

int GetMaxAreaIncludeMid(int left, int right)
{
    int lp = ( left + right ) / 2;
    int rp = lp + 1;
    
    int minHeight = std::min(fence[lp], fence[rp]);
    int maxArea = (rp - lp + 1) * minHeight;
    
    while(left != lp || right != rp)
    {
        int targetPivot;
        if(left == lp)
            targetPivot = ++rp;
        else if(right == rp)
            targetPivot = --lp;
        else if(fence[lp-1] < fence[rp+1])
            targetPivot = ++rp;
        else
            targetPivot = --lp;
        
        minHeight = std::min(minHeight, fence[targetPivot]);
        maxArea = std::max(maxArea, (rp - lp + 1) * minHeight);
    }
    
    return maxArea;
}

int GetMaxArea(int left, int right)
{
    if(left == right)   return fence[left];
    int mid = (left + right) / 2;
    int ret = std::max(GetMaxArea(left, mid), GetMaxArea(mid+1, right));
    return std::max(ret, GetMaxAreaIncludeMid(left, right));
}

int main()
{
    int TC;
    std::cin >> TC;
    while(TC--)
    {
        std::cin >> fenceCount;
        for(int i = 0 ; i < fenceCount ; i++)
            std::cin >> fence[i];
        std::cout << GetMaxArea(0, fenceCount - 1) << std::endl;
    }
    return 0;
}
