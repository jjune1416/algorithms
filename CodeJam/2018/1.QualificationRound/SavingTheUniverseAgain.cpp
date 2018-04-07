//
//  SavingTheUniverseAgain.cpp
//  https://codejam.withgoogle.com/2018/challenges/00000000000000cb/dashboard
//
//  Created by Ghost on 2018. 4. 7..
//  Copyright © 2018년 Ghost. All rights reserved.
//

#include <string>
#include <iostream>

int D;
std::string P;
const int MAX = 30;
int IP[MAX];
int length;

int FindRightMostConvert()
{
    for(int i = length - 2 ; i >= 0; i--)
        if(IP[i] == 0 && IP[i+1] != 0)
            return i;
    return -1;
}

int HowManyTimes(int sumPower, int shield, int count)
{
    if(sumPower <= shield)
        return count;
    
    int index = FindRightMostConvert();
    if(index == -1) return -1;
    std::swap(IP[index], IP[index + 1]);
    IP[index] /= 2;
    return HowManyTimes(sumPower - IP[index], shield, count + 1);
}

int main()
{
    int TC;
    std::cin >> TC;
    for(int tc = 1; tc <= TC ; tc++)
    {
        std::cin >> D >> P;
        length = (int)P.length();
        int power = 1;
        int sumPower = 0;
        for(int i = 0 ;i < length ; i++)
        {
            if(P[i] == 'C')
            {
                power *= 2;
                IP[i] = 0;
            }
            else
            {
                IP[i] = power;
                sumPower += power;
            }
        }
        int ans = HowManyTimes(sumPower, D, 0);
        if(ans == -1)
            std::cout << "Case #" << tc << ": IMPOSSIBLE" << std::endl;
        else
            std::cout << "Case #" << tc << ": " << ans << std::endl;
    }
    return 0;
}
