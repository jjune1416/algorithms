//
//  quadtree.cpp
//  https://algospot.com/judge/problem/read/QUADTREE
//
//  Created by Ghost on 2018. 1. 16..
//  Copyright © 2018년 Ghost. All rights reserved.
//

#include <iostream>
#include <string>

std::string solve(int& index, std::string input)
{
    std::string output = "";
    if(input.at(index) != 'x')
        return input.substr(index++, 1);
    
    index++;
    std::string fir = solve(index, input);
    std::string sec = solve(index, input);
    std::string thr = solve(index, input);
    std::string fou = solve(index, input);
    
    return "x" + thr + fou + fir + sec;
}

int main() {
    int TC;
    std::cin >> TC;
    while(TC--)
    {
        std::string input;
        std::cin >> input;
        int index = 0;
        std::cout << solve(index, input) << std::endl;
    }
    
    return 0;
}
