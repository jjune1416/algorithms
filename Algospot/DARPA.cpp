//
//  DARPA.cpp
//  https://algospot.com/judge/problem/read/DARPA
//
//  Created by Ghost on 2018. 3. 18..
//  Copyright © 2018년 Ghost. All rights reserved.
//

#include <iostream>

const int MAX = 200;
double spot[MAX];

bool IsPossibleGap(int cameraCount, int spotCount, double mid)
{
    int count = 1;
    double prevSpot = spot[0];
    for(int i = 1; i < spotCount ; i++)
    {
        if(spot[i] - prevSpot >= mid)
        {
            prevSpot = spot[i];
            count++;
        }
    }
    return count >= cameraCount;
}

double GetMaximumGap(int cameraCount, int spotCount, double min, double max)
{
    if(max - min < 1e-3)    return min;
    double mid = (min + max) / 2;
    if(IsPossibleGap(cameraCount, spotCount, mid))
        return GetMaximumGap(cameraCount, spotCount, mid, max);
    return GetMaximumGap(cameraCount, spotCount, min, mid);
}

int main()
{
    int TC;
    std::cin >> TC;
    std::cout << std::fixed;
    std::cout.precision(2);
    while(TC--)
    {
        int N, M;
        std::cin >> N >> M;
        for (int i = 0 ;i < M; i++)
            std::cin >> spot[i];
        std::cout << GetMaximumGap(N, M, 0.0, 240.0) << std::endl;
    }
    
    return 0;
}
