//
//  3-2 StackAndMinimum.cpp
//  CrackTheCodingInterview
//
//  push�� pop�� �� ���� ����� �ƴ϶�,
//  �ּڰ��� ���� ���Ҹ� ��ȯ�ϴ� min ������ ���� ������ ��� ������ �� �ְڴ°�?
//  Push, pop�׸��� min�� ���� O(1)�ð��� ó���Ǿ�� �Ѵ�.
//
//  Created by Ghost on 2018. 2. 20..
//  Copyright �� 2018�� Ghost. All rights reserved.
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
