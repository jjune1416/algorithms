//
//  3-2 StackAndMinimum.cpp
//  CrackTheCodingInterview
//
//  push와 pop의 두 가지 연산뿐 아니라,
//  최솟값을 갖는 원소를 반환하는 min 연산을 갖춘 스택은 어떻게 구현할 수 있겠는가?
//  Push, pop그리고 min은 공히 O(1)시간에 처리되어야 한다.
//
//  Created by Ghost on 2018. 2. 20..
//  Copyright ⓒ 2018년 Ghost. All rights reserved.
//

#include <algorithm>

const int STACK_TOP = 100;

int stack_val[STACK_TOP + 1];
int stack_min[STACK_TOP + 1];
int top = -1;

void push(int item)
{
    if(top == STACK_TOP)
        return;
    
    stack_val[++top] = item;
    if(top == 0)
        stack_min[top] = item;
    else
        stack_min[top] = std::min(stack_min[top-1], item);
}

int pop()
{
    if(top == -1)
        return -1;
    return stack_val[top--];
}

int min()
{
    return stack_min[top];
}
