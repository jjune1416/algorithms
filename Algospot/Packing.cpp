//
//  Packing.cpp
//  https://algospot.com/judge/problem/read/PACKING
//
//  Created by Ghost on 2018. 1. 31..
//  Copyright © 2018년 Ghost. All rights reserved.
//

#include <iostream>
#include <string>

const int MAX_ITEM = 101;
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
int memoN[MAX_ITEM][MAX_VOLUME];
int memoC[MAX_ITEM][MAX_VOLUME];
_item item[MAX_ITEM];

int GetMaxHopeness(int itemNum, int leftVolume)
{
    if(itemNum > itemCount) return -1;
    
    int ret = memoH[itemNum][leftVolume];
    if(ret != -1)   return ret;
    
    ret = 0;
    for(int i = itemNum + 1 ; i <= itemCount; i++)
    {
        if(item[i].volume > leftVolume) continue;
        int new_ret = item[i].hopeness + GetMaxHopeness(i, leftVolume - item[i].volume);
        if(ret < new_ret)
        {
            ret = new_ret;
            memoN[itemNum][leftVolume] = i;
            memoC[itemNum][leftVolume] = memoC[i][leftVolume - item[i].volume] + 1;
        }
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
        item[0].set("", 0, 0);
        for(int i = 1 ; i <= itemCount; i++)
        {
            std::string name;
            int volume;
            int hopeness;
            std::cin >> name >> volume >> hopeness;
            item[i].set(name, volume, hopeness);
        }
        
        for(int i = 0 ;i <= itemCount ;i++)
        {
            for(int j = 0 ;j <=  totalVolume; j++)
            {
                memoH[i][j] = memoN[i][j] = - 1;
                memoC[i][j] = 0;
            }
        }
    
        std::cout << GetMaxHopeness(0, totalVolume) << " " << memoC[0][totalVolume] << std::endl;
        int curVolume = totalVolume;
        int curItem = memoN[0][curVolume];
        while(curItem != -1)
        {
            std::cout << item[curItem].name << std::endl;
            curVolume -= item[curItem].volume;
            curItem = memoN[curItem][curVolume];
        }
    }
    return 0;
}
