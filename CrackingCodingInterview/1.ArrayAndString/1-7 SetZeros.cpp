//
//  1-7 SetZeros.cpp
//  CrackTheCodingInterview
//
//  M x N 행렬을 순회하면서 0인 원소를 발견하면,
//  해당 원소가 속한 행과 열의 모든 원소를 0으로 설정하는 알고리즘을 작성하라.
//
//  Created by Ghost on 2018. 2. 13..
//  Copyright © 2018년 Ghost. All rights reserved.
//

#include<vector>

void SetZeros(std::vector< std::vector<int> > &arr)
{
    if(arr.empty()) return;
    
    int M = static_cast<int>(arr.size());
    int N = static_cast<int>(arr[0].size());
    
    std::vector<std::pair<int, int>>  zeros;
    for(int y = 0 ; y < M ; y++)
        for(int x = 0 ; x < N ;x++)
            if(arr[y][x] == 0)
                zeros.push_back(std::make_pair(y,x));
    
    for(auto iter = zeros.begin(); iter < zeros.end(); iter++)
    {
        int y = iter->first;
        int x = iter->second;
        for(int i = 0 ;i < N ;i++)
            arr[y][i] = 0;
        for(int i = 0 ;i < M ;i++)
            arr[i][x] = 0;
    }
}
