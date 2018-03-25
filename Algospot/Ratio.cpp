//
//  Ratio.cpp
//  https://algospot.com/judge/problem/read/RATIO
//
//  Created by Ghost on 2018. 3. 25..
//  Copyright © 2018년 Ghost. All rights reserved.
//

#include <iostream>

bool IsPossibleAns(int N, int M, int val)
{
    long long newM = val + (long long)M;
    long long newN = val + (long long)N;
    return (((long long)M * 100) / N) < (newM * 100 / newN);
}

int BinarySearchGames(int N, int M, int low, int high)
{
    if(low >= high) return low;
    int mid = ((unsigned)low + (unsigned)high) >> 1;
    if(IsPossibleAns(N, M, mid))
        return BinarySearchGames(N, M, low, mid);
    else
        return BinarySearchGames(N, M, mid + 1, high);
}

int Games(int N, int M)
{
    long long newM = 2000000000L + (long long)M;
    long long newN = 2000000000L + (long long)N;
    if((int)(((long long)M * 100) / N) == (int)(newM * 100 / newN)) return -1;
    return BinarySearchGames(N, M, 0, 2000000000);
}

int main()
{
    int TC;
    std::cin >> TC;
    while(TC--)
    {
        int N, M;
        std::cin >> N >> M;
        std::cout << Games(N, M) << std::endl;
    }
    return 0;
}
