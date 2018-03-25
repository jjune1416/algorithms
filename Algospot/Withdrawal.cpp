//
//  Withdrawal.cpp
//  https://algospot.com/judge/problem/read/WITHDRAWAL
//
//  Created by Ghost on 2018. 3. 25..
//  Copyright © 2018년 Ghost. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

const int MAX = 1000;

struct _rank
{
    int R;
    int C;
};
_rank rank[MAX];
int N, K;

bool IsPossibleAnswer(double ans)
{
    std::priority_queue<double, std::vector<double>, std::greater<double>> pq;
    for(int i = 0 ; i < N ;i++)
    {
        _rank& r = rank[i];
        pq.push(r.R - r.C * ans);
    }
    double sum = 0.0;
    for(int i = 0 ; i < K ; i++)
    {
        sum += pq.top();
        pq.pop();
    }
    return (sum <= 0.0);
}

double BinarySearchGrade(double left, double right)
{
    if(right - left <= 1e-10) return left;
    double mid = (left + right) / 2;
    if(IsPossibleAnswer(mid))
        return BinarySearchGrade(left, mid);
    else
        return BinarySearchGrade(mid, right);
}

double GetMinGrade()
{
    return BinarySearchGrade(0.0, 1.0);
}

int main()
{
    int TC;
    std::cin >> TC;
    std::cout << std::fixed;
    std::cout.precision(10);
    while(TC--)
    {
        std::cin >> N >> K;
        for(int i = 0 ;i < N; i++)
            std::cin >> rank[i].R >> rank[i].C;
        std::cout << GetMinGrade() << std::endl;
    }
    
    return 0;
}
