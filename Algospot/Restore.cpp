//
//  Restore.cpp
//  https://algospot.com/judge/problem/read/RESTORE
//
//  Created by Ghost on 2018. 2. 9..
//  Copyright © 2018년 Ghost. All rights reserved.
//

#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>

const int MAX_WORD_COUNT = 15;
const int MAX_WORD_LEN = 20;

int wordCount;
std::string word[MAX_WORD_COUNT];
std::string memo[1<<15];

std::string GetShortestWord(int depth, int bitMask)
{
    if(depth == wordCount)  return "";
    
    std::string& ret = memo[bitMask];
    if(ret != "")   return ret;
    
    ret += std::string(15 * 20 + 1, 'a');
    for(int taken = 0 ; taken < wordCount ;taken++)
    {
        if(bitMask & 1 << taken)    continue;
        
        std::string left = word[taken];
        std::string right = GetShortestWord(depth + 1, bitMask | 1 << taken);

        std::string candidate;
        // sub string
        for(int pivot = 0 ; pivot + left.length() <= std::min(MAX_WORD_LEN, int(right.length())); pivot++)
        {
            if(left == right.substr(pivot, left.length()))
            {
                candidate = right;
                break;
            }
        }
        if(candidate == "")
        {
            // 겹침
            for(int dupLen = static_cast<int>(std::min(left.length(), right.length())); dupLen >= 0 ; dupLen--)
            {
                if(left.substr(left.length() - dupLen, dupLen) == right.substr(0, dupLen))
                {
                    candidate = left.substr(0, left.length() - dupLen) + right;
                    break;
                }
            }
        }
        
        if (candidate.length() < ret.length())
            ret = candidate;
        continue;
    }
    return ret;
}

int main()
{
    int TC;
    std::cin >> TC;
    while(TC--)
    {
        std::cin >> wordCount;
        for(int i = 0 ;i < wordCount ; i++)
            std::cin >> word[i];
        for(int i = 0 ;i < 1<<15; i++)
            memo[i].clear();
        std::cout << GetShortestWord(0, 0) << std::endl;
    }
    return 0;
}
