//
//  3-1 ThreeStackInOneArray.cpp
//  CrackTheCodingInterview
//
//  하나의 배열을 사용해 세 개 스택을 구현하는 방법을 설명하라.
//
//  Created by Ghost on 2018. 2. 18..
//  Copyright ⓒ 2018년 Ghost. All rights reserved.
//

const int MAX_ARR = 100;
const int STACK_SIZE = MAX_ARR / 3;
const int ERROR = -1;

int array[MAX_ARR];
int top_pivot[3] = {-1, -1, -1};

// 고정 크기 할당
bool IsEmpty(int stackNumber)
{
   return top_pivot[stackNumber] == -1;
}

bool IsFull(int stackNumber)
{
   return top_pivot[stackNumber] >= STACK_SIZE - 1;
}

int Top(int stackNumber)
{
   if(IsEmpty(stackNumber))
       return ERROR;
    
    int startOfStack = STACK_SIZE * stackNumber;
    return array[top_pivot[stackNumber] + startOfStack] ;
}

void Pop(int stackNumber)
{
   if(IsEmpty(stackNumber))
       return;
    
    array[top_pivot[stackNumber]--];
}

void Push(int stackNumber, int item)
{
    if(IsFull(stackNumber))
        return;
    
    int startOfStack = STACK_SIZE * stackNumber;
    array[++top_pivot[stackNumber] + startOfStack] = item;
}

// 유연 공간 분할 (난이도 상)
// TODO