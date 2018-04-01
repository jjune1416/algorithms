//
//  CruiseControl.cpp
//  https://codejam.withgoogle.com/2018/challenges/0000000000000130/dashboard/0000000000000524
//
//  Created by Ghost on 2018. 4. 1..
//  Copyright © 2018년 Ghost. All rights reserved.
//

#include <iostream>

struct _horse
{
    int dist;
    int speed;
};

_horse horse[10000];
int totalDist, N;

bool IsPossibleSpeed(double speed)
{
    double duration = (double)totalDist / speed;
    for(int i = 0 ;i < N; i++)
    {
        _horse& h = horse[i];
        if((double)h.speed * duration < (double)h.dist)
            return false;
    }
    return true;
}

long double MaxSpeed(long double min, long double max)
{
    for(int i = 0 ;i < 200; i++)
    {
        long double mid = (max + min) / 2.;
        if(IsPossibleSpeed(mid))
            min = mid;
        else
            max = mid;
    }
    return (max + min) / 2.;
}

int main()
{
    int TC;
    std::cin >> TC;
    std::cout << std::fixed;
    std::cout.precision(8);
    
    for(int tc = 1 ; tc <= TC; tc++)
    {
        std::cin >> totalDist >> N;
        for(int i = 0; i < N; i++)
        {
            int tempDist;
            std::cin >> tempDist >> horse[i].speed;
            horse[i].dist = totalDist - tempDist;
        }
        std::cout << "Case #" << tc << ": " << MaxSpeed(0.0, (long double)(1e18)) << std::endl;
    }
    
    return 0;
}
