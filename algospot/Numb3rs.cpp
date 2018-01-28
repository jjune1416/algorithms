//
//  Numb3rs.cpp
//  https://algospot.com/judge/problem/read/NUMB3RS
//
//  Created by Ghost on 2018. 1. 28..
//  Copyright © 2018년 Ghost. All rights reserved.
//

#include <iostream>

const int MAX_TOWN = 50;
const int MAX_DAY = 101;

int prison, destnation, answerCount;
int answerTown[MAX_TOWN];
int townCount, dayCount;
int townGraph[MAX_TOWN][MAX_TOWN];
double probablity[MAX_DAY][MAX_TOWN];
int adjTownCount[MAX_TOWN];

void Input()
{
    std::cin >> townCount >> dayCount >> prison;
    for(int i = 0 ; i < townCount ; i++)
        for(int j = 0 ;j <townCount ; j++)
            std::cin >> townGraph[i][j];
    std::cin >> answerCount;
    for(int i = 0 ; i < answerCount ; i++)
        std::cin >> answerTown[i];
}

void PreCalc()
{
    for(int i = 0 ; i <= dayCount ; i++)
        for(int j = 0; j < townCount; j++)
            probablity[i][j] = -1.;
    
    for(int i = 0 ;i < townCount; i++)
        probablity[0][i] = 0.;
    probablity[0][prison] = 1.;
    
    for(int i = 0 ; i < townCount; i++)
        adjTownCount[i] = 0;
    for(int i = 0 ;i < townCount; i++)
        for(int j = 0 ;j < i; j++)
            if(townGraph[i][j])
                adjTownCount[i]++, adjTownCount[j]++;
}

double GetProbablity(int day, int town)
{
    double& ret = probablity[day][town];
    if(ret >= 0.)   return ret;
    
    ret = 0.;
    for(int i = 0 ; i < townCount ; i++)
        if(townGraph[town][i])
            ret += GetProbablity(day-1, i) / adjTownCount[i];
    
    return ret;
}

int main()
{
    int TC;
    std::cin >> TC;
    std::cout.precision(8);
    while(TC--)
    {
        Input();
        PreCalc();
        for(int i = 0 ; i < answerCount ; i++)
            std::cout << GetProbablity(dayCount, answerTown[i])<< " ";
        std::cout << std::endl;
    }
    
    return 0;
}
