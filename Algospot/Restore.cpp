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

const int MAX_WORD_COUNT = 16;

int wordCount;
std::string word[MAX_WORD_COUNT];
int memo[1<<MAX_WORD_COUNT][MAX_WORD_COUNT];
int dupLength[MAX_WORD_COUNT][MAX_WORD_COUNT];

int GetDupleicatedLength(int indexLeft, int indexRight)
{
    int& ret = dupLength[indexLeft][indexRight];
    if (ret != -1)  return ret;
    
    std::string left = word[indexLeft];
    std::string right = word[indexRight];
    
    /*
    for(int pivot = 0 ; pivot + left.length() <= right.length(); pivot++)
        if(left == right.substr(pivot, left.length()))
            return ret = (int)left.length();
    
    if(right.find(left) != -1)
        return ret = (int)left.length();
     */
    
    for(int dupLen = (int)(std::min(left.length(), right.length())); dupLen > 0 ; dupLen--)
        if(left.substr(left.length() - dupLen) == right.substr(0, dupLen))
            return ret = dupLen;
    
    return ret = 0;
}

int GetShortestLength(int before, int bitMask)
{
    if(bitMask == (1 << (wordCount + 1)) - 1)  return (int)word[before].length();
    
    int& ret = memo[bitMask][before];
    if(ret != -1)   return ret;
    
    ret = 15 * 20 + 1;
    for(int taken = 1 ; taken <= wordCount ;taken++)
    {
        if(bitMask & 1 << taken)    continue;

        int dup = GetDupleicatedLength(before, taken);
        int rightLength = GetShortestLength(taken, bitMask | 1 << taken);
        ret = std::min<int>(ret, (int)word[before].length() + rightLength - dup);
    }
    return ret;
}

std::string GetShortestWord(int before, int bitMask)
{
    if(bitMask == (1 << (wordCount + 1)) - 1)  return word[before];
    
    int index = 0;
    for(int taken = 1 ; taken <= wordCount ; taken++)
    {
        if(bitMask & 1 << taken)    continue;
        
        int dup = GetDupleicatedLength(before, taken);
        int rightLength = GetShortestLength(taken, bitMask | 1 << taken);
        if(GetShortestLength(before, bitMask) == (int)word[before].length() + rightLength - dup)
            index = taken;
    }
    return word[before].substr(0, word[before].length() - GetDupleicatedLength(before, index))
            + GetShortestWord(index, bitMask | 1 << index);
}

int main()
{
    int TC;
    std::cin >> TC;
    while(TC--)
    {
        std::cin >> wordCount;
        for(int i = 1 ;i <= wordCount ; i++)
            std::cin >> word[i];
        memset(memo, -1, sizeof(memo));
        memset(dupLength, -1, sizeof(dupLength));
        
        int mask = 1;
        for(int i = 1; i <= wordCount ; i++)
            for(int j = 1; j <= wordCount ; j++)
                if(i != j && word[i].find(word[j]) != -1 && !(word[i] == word[j] && i > j))
                    mask |= 1 << j;
        
        std::cout << GetShortestWord(0, mask) << std::endl;
    }
    return 0;
}
