//
//  Morse.cpp
//  https://algospot.com/judge/problem/read/MORSE
//
//  Created by Ghost on 2018. 2. 4..
//  Copyright © 2018년 Ghost. All rights reserved.
//

#include <iostream>
#include <string>

const int MAX_MORSE = 101;

int memo[MAX_MORSE][MAX_MORSE];

int HowManyMorse(int N, int M)
{
    if(N < 0 || M < 0)  return 0;
    int& ret = memo[N][M];
    if(ret != -1) return ret;
    if(N == 0 || M == 0)  return ret = 1;
    return ret = HowManyMorse(N-1, M) + HowManyMorse(N, M-1);
}

std::string MakeMorse(int N, int M, int K)
{
    if(N == 0 && M == 0)    return "";
    if(N == 0)  return "o" + MakeMorse(N, M - 1, K);
    if(M == 0)  return "-" + MakeMorse(N - 1, M, K);
    
    int sh = HowManyMorse(N - 1, M);
    if(sh > K)  return "-" + MakeMorse(N - 1, M, K);
    return "o" + MakeMorse(N, M - 1, K - sh);
}

int main()
{
    int TC;
    std::cin >> TC;
    for(int i = 0 ;i < MAX_MORSE; i++)
        for(int j = 0 ;j < MAX_MORSE; j++)
            memo[i][j] = -1;
    while(TC--)
    {
        int N, M, K;
        std::cin >> N >> M >> K;
        std::cout << MakeMorse(N, M, K - 1) << std::endl;
    }
    return 0;
}
