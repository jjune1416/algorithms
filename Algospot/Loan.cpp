//
//  Loan.cpp
//  https://algospot.com/judge/problem/read/LOAN
//
//  Created by Ghost on 2018. 3. 25..
//  Copyright © 2018년 Ghost. All rights reserved.
//

#include <iostream>

bool IsPossibleAns(double N, int M, double P, double C)
{
    for(int i = 0 ; i < M; i++)
        N = N * P - C;
    return (N <= 0.0);
}

double BinarySearchRedeem(double N, int M, double P, double low, double high, int depth)
{
    if(depth >= 100)    return low;
    double mid = (low + high) / 2;
    if(IsPossibleAns(N, M, P, mid))
        return BinarySearchRedeem(N, M, P, low, mid, depth + 1);
    else
        return BinarySearchRedeem(N, M, P, mid, high, depth + 1);
}

double RedeemAmount(double N, int M, double P)
{
    return BinarySearchRedeem(N, M, (P / 1200.0) + 1.0, 0.0, N * 50.0, 0);
}

int main()
{
    int TC;
    std::cin >> TC;
    std::cout << std::fixed;
    std::cout.precision(10);
    while(TC--)
    {
        int M;
        double N, P;
        std::cin >> N >> M >> P;
        std::cout <<RedeemAmount(N, M, P) << std::endl;
    }
    return 0;
}
