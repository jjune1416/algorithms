//
//  TroubleSort.cpp
//  https://codejam.withgoogle.com/2018/challenges/00000000000000cb/dashboard/00000000000079cb
//
//  Created by Ghost on 2018. 4. 7..
//  Copyright © 2018년 Ghost. All rights reserved.
//

#include <algorithm>
#include <iostream>
#include <vector>

int numberCount;
std::vector<int> leftArr;
std::vector<int> rightArr;

int LeftMostWrong()
{
    std::sort(leftArr.begin(), leftArr.end());
    std::sort(rightArr.begin(), rightArr.end());
    for(int i = 0 ;i < numberCount - 1; i++)
    {
        if(i % 2)
        {
            int leftIndex = ( i + 1 ) / 2;
            int rightIndex = i / 2;
            if(leftArr[leftIndex] < rightArr[rightIndex])
                return i;
        }
        else
        {
            int leftIndex = i / 2;
            int rightIndex = i / 2;
            if(leftArr[leftIndex] > rightArr[rightIndex])
                return i;
        }
    }
    return -1;
}

int main()
{
    int TC;
    std::cin >> TC;
    for(int tc = 1; tc <= TC ; tc++)
    {

        std::cin >> numberCount;
        leftArr.clear();
        rightArr.clear();
        for(int i = 0 ;i < numberCount; i++)
        {
            int temp;
            std::cin >> temp;
            if(i%2)
                rightArr.push_back(temp);
            else
                leftArr.push_back(temp);
        }
        
        int ans = LeftMostWrong();
        if(ans == -1)
            std::cout << "Case #" << tc << ": OK" << std::endl;
        else
            std::cout << "Case #" << tc << ": " << ans << std::endl;
    }
    return 0;
}
