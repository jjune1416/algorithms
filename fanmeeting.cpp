//
//  main.cpp
//  fanmeeting
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

std::vector<int> vectorAdd(const std::vector<int>& a, const std::vector<int>& b, int mult)
{
    int an = a.size();
    int bn = b.size();
    int cn = std::max(an, bn + mult);
    
    std::vector<int> c(a);
    c.resize(cn);
    
    for(int i = 0 ;i <bn; i++)
        c[mult + i] += b[i];
    
    //normalize;
    
    return c;
}

std::vector<int> vectorSub(const std::vector<int>& a, const std::vector<int>& b)
{
    int an = a.size();
    int bn = b.size();
    
    std::vector<int> c(a);
    c.resize(std::max(an, bn));
    for(int i = 0 ;i < bn; i++)
        c[i] -= b[i];
    
    return c;
}

std::vector<int> generalMult(const std::vector<int>& a, const std::vector<int>& b)
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

std::vector<int> karatsuba(const std::vector<int>& a, const std::vector<int>& b)
{
    std::vector<int> result;
    
    int an = a.size();
    int bn = b.size();
    
    if (an < bn)    karatsuba(b, a);
    if (an == 0 || bn == 0)     return result;
    if (an < 50)                return generalMult(a,b);
    
    int half = an >> 1;
    
    std::vector<int> a0(a.begin(), a.begin() + half);
    std::vector<int> a1(a.begin() + half, a.end());
    std::vector<int> b0(b.begin(), std::min(b.end(), b.begin() + half));
    std::vector<int> b1(std::min(b.end(), b.begin() + half), b.end());
    
    std::vector<int> c0 = karatsuba(a0, b0);
    std::vector<int> c2 = karatsuba(a1, b1);
    
    std::vector<int> a2 = vectorAdd(a0, a1, 0);
    std::vector<int> b2 = vectorAdd(b0, b1, 0);
    
    std::vector<int> c1 = karatsuba(a2, b2);
    c1 = vectorSub(c2, c0);
    c1 = vectorSub(c2, c1);
    
    result = vectorAdd(result, c2, half * 2);
    result = vectorAdd(result, c1, half);
    result = vectorAdd(result, c0, 0);
    
    return result;
}

int HowManyHugs()
{
    int fan_count = i_fans.size();
    int member_count = i_members.size();
    std::vector<int> mult = karatsuba(i_fans, i_members);
 
    int hug_count = 0;
    for(int i = member_count-1; i < fan_count; i++)
        hug_count += !mult[i];
    
    return hug_count;
}

void input()
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
        input();
        std::cout << HowManyHugs() << std::endl;
    }
    return 0;
}
