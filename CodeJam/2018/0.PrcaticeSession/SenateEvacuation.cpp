//
//  SenateEvacuation.cpp
//  https://codejam.withgoogle.com/2018/challenges/0000000000000130/dashboard/00000000000004c0
//
//  Created by Ghost on 2018. 4. 1..
//  Copyright © 2018년 Ghost. All rights reserved.
//

#include <queue>
#include <vector>
#include <string>
#include <iostream>

struct Senate
{
    int count;
    char name;
    
    bool operator<(const Senate rhs) const
    {
        return count < rhs.count;
    }
};

int N;
Senate P[26];


std::string EvacuateSequence()
{
    std::string ans;
    std::priority_queue<Senate> pq;
    for(int i = 0 ;i < N; i++)
        pq.push(P[i]);
    
    while(!pq.empty())
    {
        Senate top = pq.top();
        pq.pop();
        ans = ans + top.name;
        if(--top.count)
            pq.push(top);
    }
    
    return ans;
}

int main()
{
    int TC;
    std::cin >> TC;
    for(int i = 0 ; i < 26 ; i++)
        P[i].name = 'A' + i;
    for(int tc = 1 ; tc <= TC ; tc++)
    {
        std::cin >> N;
        for(int i = 0 ; i < N ; i++)
            std::cin >> P[i].count;
        
        const std::string ans = EvacuateSequence();
        
        std::cout << "Case #" << tc << ":";
        const int isOdd = ans.length() % 2;
        if(isOdd)
            std::cout << " " << ans[0];
        for(int i = 0 ;i < ans.length() / 2 ; i++)
            std::cout << " " << ans[i * 2 + isOdd] << ans[i * 2 + 1 + isOdd];
        std::cout << std::endl;
    }
    return 0;
}
