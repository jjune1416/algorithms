//
//  LunchBox.cpp
//  https://algospot.com/judge/problem/read/LUNCHBOX
//
//  Created by Ghost on 2018. 3. 3..
//  Copyright © 2018년 Ghost. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

const int MAX_LUNCH_BOX = 10000;

struct _lunchBox
{
    int warmingTime;
    int eatingTime;
};

bool operator<(const _lunchBox lhs, const _lunchBox rhs)
{
    if(lhs.eatingTime == rhs.eatingTime)
        return lhs.warmingTime < rhs.warmingTime;
    return lhs.eatingTime < rhs.eatingTime;
}

long long GetMinTime(_lunchBox lunchBox[], int sizeOfLunchBox)
{
    std::priority_queue<_lunchBox, std::vector<_lunchBox>, std::less<_lunchBox> > pq;
    for(int i = 0 ; i < sizeOfLunchBox ; i++)
        pq.push(lunchBox[i]);
    
    long long warmingTime = 0;
    long long ret = 0;
    
    while(!pq.empty())
    {
        _lunchBox top = pq.top();
        pq.pop();
        warmingTime += top.warmingTime;
        ret = std::max(ret, warmingTime + top.eatingTime);
    }
    return ret;
}

int main()
{
    int TC;
    std::cin >> TC;
    while(TC--)
    {
        _lunchBox lunchBox[MAX_LUNCH_BOX];
        int amountOfLunchBox;
        std::cin >> amountOfLunchBox;
        for(int i = 0 ;i < amountOfLunchBox ; i++)
            std::cin >> lunchBox[i].warmingTime;
        for(int i = 0 ;i < amountOfLunchBox ; i++)
            std::cin >> lunchBox[i].eatingTime;
        std::cout << GetMinTime(lunchBox, amountOfLunchBox) << std::endl;
    }
    return 0;
}
