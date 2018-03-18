//
//  Arctic.cpp
//  https://algospot.com/judge/problem/read/ARCTIC
//
//  Created by Ghost on 2018. 3. 18..
//  Copyright © 2018년 Ghost. All rights reserved.
//

#include <cmath>
#include <iostream>

struct _point
{
    double x, y;
    int parent;
};

_point point[100];
double dist[100][100];

int Find(int i)
{
    int& ip = point[i].parent;
    if(ip == i) return i;
    return ip = Find(ip);
}

void Union(int i, int j)
{
    point[Find(i)].parent = point[Find(j)].parent;
}

bool IsPossibleRange(int count, double range)
{
    for(int i = 0 ;i < count ; i++)
        point[i].parent = i;
    
    for(int i = 0; i < count ; i++)
    {
        for(int j = 0 ; j < count ; j++)
        {
            if(i == j)  continue;
            if(dist[i][j] <= range)
            {
                Union(i,j);
            }
        }
    }
    
    int parent = Find(0);
    for(int i = 1 ;i < count ;i++)
        if(Find(i) != parent)
            return false;
    return true;
}

double GetMinRange(int count, double min, double max)
{
    if(max - min < 1e-7)    return min;
    
    double mid = (min + max) / 2;
    if(IsPossibleRange(count , mid))
        return GetMinRange(count, min, mid);
    return GetMinRange(count, mid, max);
}

int main()
{
    std::cout << std::fixed;
    std::cout.precision(2);
    
    int TC;
    std::cin >> TC;
    while(TC--)
    {
        int n;
        std::cin >> n;
        for(int i = 0 ;i < n; i++)
            std::cin >> point[i].x >> point[i].y;
        
        for(int i = 0 ;i < n; i++)
            for(int j = 0 ;j < n; j++)
                if(i == j)
                    dist[i][j] = 0.0;
                else
                    dist[i][j] = dist[j][i] = sqrt(pow(point[i].y - point[j].y, 2) + pow(point[i].x - point[j].x, 2));

        std::cout << GetMinRange(n, 0.0, 1500.0) << std::endl;
    }
}
