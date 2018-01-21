//
//  wild_card.cpp
//  https://algospot.com/judge/problem/read/WILDCARD
//
//  Created by Ghost on 2018. 1. 21..
//  Copyright © 2018년 Ghost. All rights reserved.
//

#include <algorithm>
#include <iostream>
#include <string.h>
#include <vector>

const int MAX_FILE = 100;

std::string card;

int fileCount;
std::vector<std::string> fileNames;
int retCache[MAX_FILE+1][MAX_FILE+1];

void Input()
{
    std::string fileName;
    std::cin >> card;
    std::cin >> fileCount;
    fileNames.clear();
    for(int i = 0;i < fileCount; i++)
    {
        std::cin >> fileName;
        fileNames.push_back(fileName);
    }
}

bool IsPossibleName(std::string fileName, int cardPivot, int filePivot)
{
    int& ret = retCache[cardPivot][filePivot];
    if(ret != -1) return ret;
    
    if(cardPivot == card.size())
    {
        if(filePivot != fileName.size())
            return ret = false;
        return ret = true;
    }
    else if(filePivot == fileName.size() && card[cardPivot] != '*')
    {
        return ret = false;
    }
    
    if(card[cardPivot] == '?')
    {
        ret = IsPossibleName(fileName, cardPivot + 1, filePivot + 1);
    }
    else if(card[cardPivot] == '*')
    {
        for(int i = filePivot; i <= fileName.size(); i++)
        {
            ret = false;
            
            if(IsPossibleName(fileName, cardPivot + 1, i))
            {
                ret = true;
                break;
            }
        }
    }
    else if(card[cardPivot] == fileName[filePivot])
    {
        ret = IsPossibleName(fileName, cardPivot + 1, filePivot + 1);
    }
    else
    {
        ret = false;
    }
    
    return ret;
}

void ResetCache()
{
    for(int i = 0 ;i <= MAX_FILE ; i++)
    {
        for(int j = 0 ; j <= MAX_FILE ; j++)
        {
            retCache[i][j] = -1;
        }
    }
}

std::vector<std::string> GetPossibleName()
{
    std::vector<std::string> ret;
    for(int i = 0 ; i< fileNames.size(); i++)
    {
        ResetCache();
        if(IsPossibleName(fileNames[i], 0 , 0))
        {
            ret.push_back(fileNames[i]);
        }
    }
    std::sort(ret.begin(), ret.end());
    return ret;
}

int main() {
    int TC;
    std::cin >> TC;
    while(TC--)
    {
        Input();
        std::vector<std::string> names = GetPossibleName();
        for(auto name : names)
        {
            std::cout << name << std::endl;
        }
    }
    return 0;
}
