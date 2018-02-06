//
//  Dragon.cpp
//  https://algospot.com/judge/problem/read/DRAGON
//
//  Created by Ghost on 2018. 2. 5..
//  Copyright © 2018년 Ghost. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <string.h>

int N, P, L;
const std::string X = "X+YF";
const std::string Y = "FX-Y";

const int MAX_N = 51;
const int INF = 1000000000;
int memoLength[MAX_N];

int GetLength(char c, int n)
{
    if(c == '+' || c == '-' || c == 'F')    return 1;
    int& ret = memoLength[n];
    if(ret != -1)   return ret;
    if(n == N) return ret = 1;
    return ret = std::min(INF, 2 + GetLength('X', n + 1) + GetLength('Y', n + 1));
}

std::string GetString(std::string str, int n, int start, int last, int index)
{
    if(n == N)
        return str.substr(std::max(0, start-index), std::min((int)str.length(), last - index) - std::max(0, start-index));
    
    std::string ret;
    for(int i = 0 ; i < str.length(); i++)
    {
        int len = GetLength(str.at(i), n);
        if(index + len > start && index < last)
        {
            char c = str.at(i);
            if(c == '+' || c == '-' || c == 'F')
                ret.push_back(c);
            else
                ret += GetString((c == 'X' ? X : Y), n + 1, start, last , index);
        }
        index += len;
    }
    return ret;
}

int main()
{
    int TC;
    std::cin >> TC;
    while(TC--)
    {
        std::cin >> N >> P >> L;
        for(int i= 0 ;i <= N ;i++) memoLength[i] = -1;
        std::cout << GetString("FX", 0, P-1, P+L-1, 0) << std::endl;
    }
    return 0;
}
