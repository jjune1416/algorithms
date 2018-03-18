//
//  CanadaTrip.cpp
//  https://algospot.com/judge/problem/read/CANADATRIP
//
//  Created by Ghost on 2018. 3. 18..
//  Copyright © 2018년 Ghost. All rights reserved.
//

#include <iostream>

struct _city
{
    unsigned totalDist;
    unsigned startDist;
    unsigned signGap;
    unsigned countOfSign;
};

int cityCount;
_city city[5000];

bool IsPossibleDist(unsigned k, int Dist)
{
    unsigned count = 0;
    for(int i = 0 ;i < cityCount; i++)
    {
        _city& c = city[i];
        
        if(c.totalDist < Dist)
            count += c.countOfSign;
        else if(Dist < c.totalDist - c.startDist)
            count += 0;
        else
            count += (Dist - (c.totalDist - c.startDist)) / c.signGap + 1;
    }
    return count <= k;
}

unsigned GetDistFromKthSign(unsigned k, unsigned min, unsigned max)
{
    if(min >= max)  return min;
    unsigned mid = (min + max) / 2;
    if(IsPossibleDist(k, mid))
        return GetDistFromKthSign(k, mid + 1, max);
    return GetDistFromKthSign(k, min, mid);
}

int main()
{
    int TC;
    std::cin >> TC;
    while(TC--)
    {
        unsigned k;
        std::cin >> cityCount >> k;
        for(unsigned i = 0 ; i < cityCount ;i++)
        {
            _city& c = city[i];
            std::cin >> c.totalDist >> c.startDist >> c.signGap;
            c.countOfSign = c.startDist / c.signGap + 1;
        }
        std::cout << GetDistFromKthSign(k - 1,  0, 0x7FFFFFFF) << std::endl;
    }
}
