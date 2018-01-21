//
//  fanmeeting.cpp
//  https://algospot.com/judge/problem/read/FANMEETING
//
//  Created by Ghost on 2018. 1. 21..
//  Copyright © 2018년 Ghost. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>

const int MAX_MEMBERS = 200000;

char c_members[MAX_MEMBERS + 1];
char c_fans[MAX_MEMBERS + 1];

std::vector<int> i_members;
std::vector<int> i_fans;

void VectorAdd(std::vector<int>& a, const std::vector<int>& b, int mult)
{
    int an = a.size();
    int bn = b.size();
    int new_an = std::max(an, bn + mult);
    
    a.resize(new_an);
    
    for(int i = 0 ;i <bn; i++)
        a[mult + i] += b[i];
}

void VectorSub(std::vector<int>& a, const std::vector<int>& b)
{
    int an = a.size();
    int bn = b.size();
    
    a.resize(std::max(an, bn));
    for(int i = 0 ;i < bn; i++)
        a[i] -= b[i];
}

std::vector<int> GeneralMult(const std::vector<int>& a, const std::vector<int>& b)
{
    std::vector<int> result;
    
    int an = a.size();
    int bn = b.size();
    
    result.resize(an + bn - 1);
    for(int i = 0 ;i < an; i++)
        for(int j  = 0 ;j < bn ; j++)
            result[i+j] += a[i] * b[j];
    
    return result;
}

std::vector<int> KaratsubaMult(const std::vector<int>& a, const std::vector<int>& b)
{
    std::vector<int> result;
    
    int an = a.size();
    int bn = b.size();
    
    if (an < bn)    KaratsubaMult(b, a);
    if (an == 0 || bn == 0)     return result;
    if (an < 50)                return GeneralMult(a,b);
    
    int half = an >> 1;
    
    std::vector<int> a0(a.begin(), a.begin() + half);
    std::vector<int> a1(a.begin() + half, a.end());
    std::vector<int> b0(b.begin(), std::min(b.end(), b.begin() + half));
    std::vector<int> b1(std::min(b.end(), b.begin() + half), b.end());
    
    std::vector<int> c0 = KaratsubaMult(a0, b0);
    std::vector<int> c2 = KaratsubaMult(a1, b1);
    
    VectorAdd(a0, a1, 0);
    VectorAdd(b0, b1, 0);
    
    std::vector<int> c1 = KaratsubaMult(a0, b0);
    VectorSub(c1, c0);
    VectorSub(c1, c2);
    
    VectorAdd(result, c2, half * 2);
    VectorAdd(result, c1, half);
    VectorAdd(result, c0, 0);
    
    return result;
}

int HowManyHugs()
{
    int fan_count = i_fans.size();
    int member_count = i_members.size();
    std::vector<int> mult = KaratsubaMult(i_fans, i_members);
 
    int hug_count = 0;
    for(int i = member_count-1; i < fan_count; i++)
        hug_count += !mult[i];
    
    return hug_count;
}

void Input()
{
    i_fans.clear();
    i_members.clear();
    std::cin >> c_members;
    std::cin >> c_fans;
    int i = 0;
    while(c_members[i])
        i_members.push_back(c_members[i++] == 'M');
    std::reverse(i_members.begin(), i_members.end());
    
    i = 0;
    while(c_fans[i])
        i_fans.push_back(c_fans[i++] == 'M');
}

int main()
{
    int TC;
    std::cin >> TC;
    while(TC--)
    {
        Input();
        std::cout << HowManyHugs() << std::endl;
    }
    return 0;
}
