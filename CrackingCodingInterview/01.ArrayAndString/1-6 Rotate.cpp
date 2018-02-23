//
//  1-6 Rotate.cpp
//  CrackTheCodingInterview
//
//  Created by Ghost on 2018. 2. 5..
//  Copyright © 2018년 Ghost. All rights reserved.
//

// 이미지를 표현하는 N * N 행렬이 있다.
// 이미지의 각 필셀은 4바이트로 표현된다. 이때 이미지를 90도 회전시키는 메서드를 작성하라.
// 부가적인 행렬을 사용하지 않고서도 할 수 있겠는가?

const int N = 5;

void Rotate(int arr[N][N])
{
    for(int y = 0 ; y < N/2; y++)
    {
        int last = N - y - 1;
        for(int x = y; x< last ; x++)
        {
            int top = arr[y][x];
            arr[y][x] = arr[N-x-1][y];
            arr[N-x-1][y] = arr[N-y-1][N-x-1];
            arr[N-y-1][N-x-1] = arr[x][N-y-1];
            arr[x][N-y-1] = top;
        }
    }
}
