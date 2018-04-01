//
//  BathroomStalls.cpp
//  https://code.google.com/codejam/contest/3264486/dashboard#s=p2
//
//  Created by Ghost on 2018. 3. 13..
//  Copyright © 2018년 Ghost. All rights reserved.
//

#include <unordered_map>
#include <iostream>
#include <vector>
#include <queue>

std::unordered_map<long long, long long> m;
std::priority_queue<long long, std::vector<long long>> pq;

long long KthWidth(long long k)
{
    long long top = pq.top();
    pq.pop();
    
    long long count = m.find(top) -> second;
    if(count >= k)  return top;
    
    long long right = top / 2;
    long long left = (top - 1) / 2;
    
    auto it = m.find(left);
    if(it == m.end())
    {
        pq.push(left);
        m[left] = count;
    }
    else
    {
        m[left] = it->second + count;
    }
    
    it = m.find(right);
    if(it == m.end())
    {
        pq.push(right);
        m[right] = count;
    }
    else
    {
        m[right] = it->second + count;
    }
    return KthWidth(k - count);
}

int main()
{
    int TC;
    std::cin >> TC;
    for(int tc = 1; tc <= TC; tc++)
    {
        long long K, N;
        std::cin >> N >> K;
        m.clear();
        pq= std::priority_queue<long long, std::vector<long long>>();
        m[N] = 1;
        pq.push(N);
        long long kthWidth = KthWidth(K);
        std::cout << "Case #" << tc << ": " << kthWidth/2 << " " << (kthWidth - 1) / 2 << std::endl;
    }
    return 0;
}
