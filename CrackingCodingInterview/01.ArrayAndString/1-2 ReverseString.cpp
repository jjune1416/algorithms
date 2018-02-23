//
//  1-2 ReverseString.cpp
//  CrackTheCodingInterview
//
//  널 문자로 끝나는 문자열을 뒤집는 reverse(char* str) 함수를 C나 C++로 구현하라.
//
//  Created by Ghost on 2018. 1. 28..
//  Copyright © 2018년 Ghost. All rights reserved.
//

void reverse(char* str)
{
    int len = 0;
    while(str[len])
        len++;
    char buf;
    for(int i = 0 ;i < len/2; i++)
    {
        buf = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = buf;
    }
}
