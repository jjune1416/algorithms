//
//  1-3 Permutation.cpp
//  CrackTheCodingInterview
//
//  문자열 두개를 입력으로 받아 그중 하나가 다른 하나의 순열인지 판별하는 메서드를 작성하라.
//
//  Created by Ghost on 2018. 1. 28..
//  Copyright © 2018년 Ghost. All rights reserved.
//

#include <algorithm>
#include <string>

// nlgn
bool Permutation1(std::string a, std::string b)
{
    if(a.size() != b.size())    return false;
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());
    return a == b;
}

// n+k
bool Permutation2(std::string a, std::string b)
{
    if(a.size() != b.size())    return false;
    int cnt[256] = {0,};
    for(int i = 0 ;i < a.size(); i++)
    {
        cnt[a[i]]++;
        cnt[b[i]]--;
    }
    
    for(int i = 0 ;i < 256; i++)
        if(cnt[i])
            return false;
    return true;
}
