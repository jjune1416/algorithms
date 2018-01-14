//
//  picnic.cpp
//  picnic
//
//  Created by Ghost on 2018. 1. 14..
//  Copyright © 2018년 Ghost. All rights reserved.
//

#include <stdio.h>

#define MAX_STUDENT 10

int numStudent;
int pairCount;

bool    friendGrid[MAX_STUDENT][MAX_STUDENT];
bool    friendTakenMemo[MAX_STUDENT];

int howManyPairsDFS(int depth)
{
    if(depth >= numStudent) return 1;
    if(friendTakenMemo[depth] == true) return howManyPairsDFS(depth + 1);
    
    int ans = 0;
    for(int i = depth + 1 ; i < numStudent; i++)
    {
        if(friendGrid[depth][i] == true && friendTakenMemo[i] == false)
        {
            friendTakenMemo[depth] = friendTakenMemo[i] = true;
            ans += howManyPairsDFS(depth + 1);
            friendTakenMemo[depth] = friendTakenMemo[i] = false;
        }
    }
    
    return ans;
}

int main() {
    int TC;
    scanf("%d", &TC);
    
    while(TC--)
    {
        scanf("%d %d", &numStudent, &pairCount);
        for(int i = 0 ;i < numStudent; i++)
        {
            friendTakenMemo[i] = false;
            for(int j = 0 ;j <numStudent; j++)
                friendGrid[i][j]= false;
        }
        for(int i = 0 ;i < pairCount; i ++)
        {
            int x, y;
            scanf("%d %d", &x, &y);
            friendGrid[x][y] = friendGrid[y][x]= true;
        }
        printf("%d\n", howManyPairsDFS(0));
    }
}
