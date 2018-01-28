//
//  ClockSync.cpp
//  https://algospot.com/judge/problem/read/CLOCKSYNC
//
//  Created by Ghost on 2018. 1. 15..
//  Copyright © 2018년 Ghost. All rights reserved.
//

#include <stdio.h>
#define NUM_CLOCK 16
#define NUM_SWITCH 10
#define BOUND 1987654321

char _switch[NUM_SWITCH][NUM_CLOCK + 1] ={
    "oooxxxxxxxxxxxxx",
    "xxxoxxxoxoxoxxxx",
    "xxxxoxxxxxoxxxoo",
    "oxxxooooxxxxxxxx",
    "xxxxxxoooxoxoxxx",
    "oxoxxxxxxxxxxxoo",
    "xxxoxxxxxxxxxxoo",
    "xxxxooxoxxxxxxoo",
    "xoooooxxxxxxxxxx",
    "xxxoooxxxoxxxoxx"};

int clock[NUM_CLOCK];
int ans;

bool isOK()
{
    for (int i = 0 ;i < NUM_CLOCK ;i++)
        if(clock[i])
            return false;
    return true;
}

void getMinCount(int depth, int count)
{
    if(count >= ans) return;
    
    if(depth == NUM_SWITCH)
    {
        if (isOK()) ans = count;
        return;
    }
    
    for(int i = 0 ;i < 4; i++)
    {
        getMinCount(depth + 1, count + i);
        for(int j = 0 ;j <NUM_CLOCK; j++)
        {
            if('o' == _switch[depth][j])
            {
                clock[j] = (clock[j] + 3) % 12;
            }
        }
    }
}

int main()
{
    int TC;
    scanf("%d", &TC);
    while(TC--)
    {
        for(int i = 0 ;i < NUM_CLOCK; i++)
        {
            scanf("%d", &clock[i]);
            clock[i] %= 12;
        }
        
        ans = BOUND;
        getMinCount(0, 0);
        printf("%d\n", (ans == BOUND) ? -1 : ans);
        
    }
    return 0;
}
