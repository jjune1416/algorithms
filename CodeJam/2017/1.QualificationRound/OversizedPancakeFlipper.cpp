//
//  Qualification Round 2017 Probalem A
//  https://code.google.com/codejam/contest/3264486/dashboard
//
//  Created by Ghost on 2018. 3. 11..
//  Copyright 2018 Ghost. All rights reserved.
//

#include <iostream>
#include <string>

inline void Flip(std::string& pancakes, int index, int S)
{
    while(S--)
    {
        pancakes[index] = (pancakes[index] == '-' ? '+' : '-');
        index++;
    }
}

int FlipTimes(std::string pancakes, int S)
{
    int times = 0;
    for(int index = 0 ; index + S <= pancakes.length() ; index++)
    {
        if(pancakes[index] == '-')
        {
            times++;
            Flip(pancakes, index, S);
        }
    }
    
    for(int index = 0 ; index < pancakes.length() ; index++)
        if(pancakes[index] == '-')
            return -1;
    return times;
}

int main()
{
    int TC;
    std::cin >> TC;
    for(int i = 0 ;i < TC ; i++)
    {
        int S;
        std::string pancakes;
        std::cin >> pancakes >> S;
        int ans = FlipTimes(pancakes, S);
        std::cout << "Case #" << i + 1 << ": ";
        if(ans == -1)
            std::cout << "IMPOSSIBLE";
        else
            std::cout << ans;
        std::cout << std::endl;
    }
}
