//
//  StrJoin.cpp
//  https://algospot.com/judge/problem/read/STRJOIN
//
//  Created by Ghost on 2018. 3. 3..
//  Copyright © 2018년 Ghost. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

int GetMinCost(const std::vector<int>& vecStr)
{
    if(vecStr.size() < 2)
        return 0;
    
    std::priority_queue<int, std::vector<int>, std::greater<int> > pq;
    for(const int& len : vecStr)
        pq.push(len);
    
    int ret = 0;
    while(pq.size() >= 2)
    {
        int fi = pq.top();
        pq.pop();
        int se = pq.top();
        pq.pop();
        
        int newLen = fi + se;
        pq.push(newLen);
        ret += newLen;
    }
    return ret;
}

int main()
{
    int TC;
    std::cin >> TC;
    while(TC--)
    {
        int amountOfStr;
        std::cin >> amountOfStr;
        
        std::vector<int> vecStr;
        for(int i = 0 ;i < amountOfStr; i++)
        {
            int buf;
            std::cin >> buf;
            vecStr.push_back(buf);
        }
        std::cout << GetMinCost(vecStr) << std::endl;
    }
    return 0;
}
