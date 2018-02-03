//
//  Packing.cpp
//  https://algospot.com/judge/problem/read/PACKING
//
//  Created by Ghost on 2018. 1. 31..
//  Copyright © 2018년 Ghost. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

const int MAX_ITEM = 100;
const int MAX_VOLUME = 1001;

struct _item
{
    std::string name;
    int volume;
    int hopeness;
    
    void set(std::string n, int v, int h)
    {
        name = n;
        volume = v;
        hopeness = h;
    };
};

int itemCount;
int totalVolume;
int memo[MAX_ITEM][MAX_VOLUME];
_item item[MAX_ITEM];

int GetMaxHopeness(int itemNum, int leftVolume)
{
    if(itemNum == itemCount) return 0;
    int& ret = memo[itemNum][leftVolume];
    if(ret != -1)   return ret;
    
    ret = GetMaxHopeness(itemNum + 1, leftVolume);
    if(leftVolume >= item[itemNum].volume)
        ret = std::max(ret, item[itemNum].hopeness + GetMaxHopeness(itemNum + 1, leftVolume - item[itemNum].volume));
    return ret;
}

int reconstruct(int itemNum, int leftVolume, std::vector<std::string>& names)
{
    if(itemNum == itemCount)    return 0;
    if(GetMaxHopeness(itemNum,leftVolume) == GetMaxHopeness(itemNum + 1,leftVolume))
        return reconstruct(itemNum + 1, leftVolume, names);
    names.push_back(item[itemNum].name);
    return reconstruct(itemNum + 1, leftVolume - item[itemNum].volume, names) + 1;
}

int main()
{
    int TC;
    std::cin >> TC;
    while(TC--)
    {
        std::cin >> itemCount >> totalVolume;
        for(int i = 0 ; i < itemCount; i++)
        {
            std::string name;
            int volume;
            int hopeness;
            std::cin >> name >> volume >> hopeness;
            item[i].set(name, volume, hopeness);
        }
        
        for(int i = 0 ;i < itemCount ;i++)
            for(int j = 0 ;j <= totalVolume; j++)
                memo[i][j] = -1;
        
        std::vector<std::string> names;
        std::cout << GetMaxHopeness(0, totalVolume) << " " << reconstruct(0, totalVolume, names) << std::endl;
        for(int i = 0 ; i < names.size() ; i++)
            std::cout << names.at(i) << std::endl;
    }
    return 0;
}
