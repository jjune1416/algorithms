//
//  Packing.cpp
//  https://algospot.com/judge/problem/read/PACKING
//
//  Created by Ghost on 2018. 1. 31..
//  Copyright © 2018년 Ghost. All rights reserved.
//

#include <iostream>
#include <string>

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
int memoH[MAX_ITEM][MAX_VOLUME];
int memoT[MAX_ITEM][MAX_VOLUME];
int memoC[MAX_ITEM][MAX_VOLUME];
_item item[MAX_ITEM];

int GetMaxHopeness(int itemNum, int leftVolume)
{
    if(leftVolume < 0)      return -987654321;
    if(itemNum >= itemCount) return 0;
    
    int ret = memoH[itemNum][leftVolume];
    if(ret != -1)   return ret;
    
    
    int retInclude = item[itemNum].hopeness + GetMaxHopeness(itemNum + 1, leftVolume - item[itemNum].volume);
    int retExclude = GetMaxHopeness(itemNum + 1, leftVolume);
    
    if(retInclude > retExclude)
    {
        ret = retInclude;
        memoC[itemNum][leftVolume] = memoC[itemNum + 1][leftVolume - item[itemNum].volume] + 1;
        memoT[itemNum][leftVolume] = 1;
    }
    else
    {
        ret = retExclude;
        memoC[itemNum][leftVolume] = memoC[itemNum + 1][leftVolume];
        memoT[itemNum][leftVolume] = 0;
    }
    
    return ret;
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
        {
            for(int j = 0 ;j <= totalVolume; j++)
            {
                memoH[i][j] = memoT[i][j] = -1;
                memoC[i][j] = 0;
            }
        }
    
        std::cout << GetMaxHopeness(0, totalVolume) << " " << memoC[0][totalVolume] << std::endl;
        int curVolume = totalVolume;
        for(int i = 0 ; i < itemCount; i++)
        {
            if(!memoT[i][curVolume])    continue;
            std::cout << item[i].name << std::endl;
            curVolume -= item[i].volume;
        }
    }
    return 0;
}
