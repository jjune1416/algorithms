//
//  Zimbabwe.cpp
//  https://algospot.com/judge/problem/read/ZIMBABWE
//
//  Created by Ghost on 2018. 2. 9..
//  Copyright © 2018년 Ghost. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <string>

const int MOD = 1000000007;

int m;
std::string price;
int memo[1<<15][20][2];

int HowManyPrice(int depth, int taken, int remain, bool less)
{
    if(depth == price.length())
        return !remain && less;
    int& ret = memo[taken][remain][less];
    if(ret != -1)   return ret;
    
    ret = 0;
    bool usedNumber[10] = {0,};
    for(int i = 0 ; i < price.length() ; i++)
    {
        if((taken >> i) & 1)  continue;
        int takenNumber = price.at(i) - '0';
        int originNumber = price.at(depth) -'0';
        if(!less && (originNumber < takenNumber))  continue;
        if(usedNumber[takenNumber]) continue;
        
        usedNumber[takenNumber] = true;
        int nextRemain = (remain * 10 + takenNumber) % m;
        bool nextLess = less || (originNumber > takenNumber);
        ret = (ret + HowManyPrice(depth + 1, taken | (1 << i), nextRemain, nextLess)) % MOD;
    }
    return ret;
}

int main()
{
    int TC;
    std::cin >> TC;
    while(TC--)
    {
        std::cin >> price >> m;
        memset(memo, -1, sizeof(int) * (1<<15) * 20 * 2);
        std::cout << HowManyPrice(0, 0, 0, false) << std::endl;
    }
    return 0;
}
