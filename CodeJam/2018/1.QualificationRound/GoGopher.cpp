//
//  GoGopher.cpp
//  https://codejam.withgoogle.com/2018/challenges/00000000000000cb/dashboard/0000000000007a30
//
//  Created by Ghost on 2018. 4. 7..
//  Copyright © 2018년 Ghost. All rights reserved.
//

#include <iostream>
#include <string.h>

const int MAX = 1001;
int arr[MAX][MAX];
int size;

void GetNewPoint(const int x, const int y, int& outX, int& outY)
{
    if(y == 1)  outY = 2;
    else if(y == size)  outY = size - 1;
    else        outY = y;
    if(x == 1)  outX = 2;
    else if(x == size)  outX = size - 1;
    else        outX = x;
}

void GoGopher()
{
    for(int i = 1 ;i <= size ; i++)
    {
        for(int j = 1 ;j <= size ; j++)
        {
            while(arr[i][j] == 0)
            {
                int x, y;
                GetNewPoint(j, i, x, y);
                std::cout << x << " " << y << std::endl;
                std::cout.flush();
                int responsedX, responsedY;
                std::cin >> responsedX >> responsedY;
                if(responsedX == 0 && responsedY == 0) return;
                if(responsedX == -1 && responsedY == -1) return;
                arr[responsedY][responsedX] = 1;
            }
        }
    }
    
}

int main(int argc, const char * argv[]) {
    int TC;
    std::cin >> TC;
    for(int tc = 1; tc <= TC ; tc++)
    {
        int A;
        std::cin >> A;
        memset(arr, 0, sizeof(arr));
        if(A == 20)
            size = 5;
        else
            size = 15;
        GoGopher();
    }
    return 0;
}
