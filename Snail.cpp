//
//  Snail.cpp
//  https://algospot.com/judge/problem/read/SNAIL
//
//  Created by Ghost on 2018. 1. 27..
//  Copyright © 2018년 Ghost. All rights reserved.
//

#include <iostream>

const int MAX = 1000;

int totalDepth;
int totalDay;

long double memo[MAX+2][MAX+1];

long double GetPossiblity(int depth, int day)
{
    long double& ret = memo[depth][day];
    if(ret >= 0)    return ret;
    
    if(day == totalDay)
        return ret = (depth < totalDepth ? 0. : 1.);
    else if(depth >= totalDepth)
        return ret = 1.;
    
    return ret = GetPossiblity(depth+1, day+1) * (0.25) + GetPossiblity(depth+2, day+1) * (0.75);
}

int main()
{
    int TC;
    std::cin >> TC;
    while(TC--)
    {
        std::cin >> totalDepth >> totalDay;
        for(int i = 0 ;i <= totalDepth + 1;i++)
            for(int j = 0 ; j <= totalDay;j++)
                memo[i][j] = -1.;
        std::cout.precision(10);
        std::cout << GetPossiblity(0,0) << std::endl;
    }
    
    return 0;
}
