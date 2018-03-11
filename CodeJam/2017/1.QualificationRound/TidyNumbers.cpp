//
//  TidyNumbers.cpp
//  https://code.google.com/codejam/contest/3264486/dashboard#s=p1
//
//  Created by Ghost on 2018. 3. 11..
//  Copyright 2018 Ghost. All rights reserved.
//

#include <iostream>
#include <string>

int FindFirstLess(std::string N)
{
    for(int i = 1 ;i < N.length(); i++)
        if(N[i] < N[i - 1])
            return i;
    return -1;
}

std::string GetTidyNumber(std::string N)
{
    int index = FindFirstLess(N);
    if(index == -1) return N;
    // switch left
    if(index > 0)
    {
        int lp = index - 1;
        char leftVal = N[lp]--;
        while(--lp >= 0 && N[lp] == leftVal)
        {
            N[lp + 1] = '9';
            N[lp]--;
        }
    }

    // switch right
    for(int rp = index; rp < N.length();rp++)
        N[rp] = '9';
    
    //zero padding
    if(N[0] == '0')
        N = N.substr(1, N.length() - 1);
    return N;
}

int main()
{
    int TC;
    std::cin >> TC;
    for(int tc = 1; tc <= TC; tc++)
    {
        std::string N;
        std::cin >> N;
        std::cout << "Case #" << tc << ": " << GetTidyNumber(N) << std::endl;
    }
    return 0;
}
