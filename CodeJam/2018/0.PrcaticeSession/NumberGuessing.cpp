//
//  NumberGuessing.cpp
//  https://codejam.withgoogle.com/2018/challenges/0000000000000130/dashboard
//
//  Created by Ghost on 2018. 4. 1..
//  Copyright © 2018년 Ghost. All rights reserved.
//

#include <iostream>
#include <string>

int bSearch(int a, int b, int depth)
{
    if(depth == 0)  return -1;
    
    int mid = ((unsigned)a + (unsigned)b) >> 1;
    std::cout << mid << std::endl;
    std::cout.flush();
    
    std::string interact;
    std::cin >> interact;
    
    if(interact == "TOO_BIG")
        return bSearch(a, mid - 1, depth - 1);
    else if(interact == "TOO_SMALL")
        return bSearch(mid + 1, b, depth - 1);
    else if(interact == "WRONG_ANSWER")
        return -1;
    return mid;
}

int main()
{
    int tc;
    std::cin >> tc;
    while(tc--)
    {
        int a, b, n;
        std::cin >> a >> b;
        std::cin >> n;
        if(bSearch(a + 1, b, n) == -1) break;
    }
    return 0;
}
