//
//  1-4 ReplaceSpaces.cpp
//  CrackTheCodingInterview
//
//  주어진 문자열 내의 모든 공백을 '%20'으로 바꾸는 메서드를 작서하라.
//  문자열 끝에 추가로 필요한 문자들을 더할 수 있는 충분한 공간이 있다고 가정하라.
//  그리고 공백을 포함하는 문자열의 길이도 함께 주어진다고 가정하라.
//
//  Created by Ghost on 2018. 1. 28..
//  Copyright © 2018년 Ghost. All rights reserved.
//

void ReplaceSpaces(char* str, int len)
{
    int spaceCnt = 0;
    for(int i = 0; i < len ; i++)
        if(str[i] == ' ')
            spaceCnt++;
    int newLen = len + spaceCnt * 2;
    str[newLen--] = 0;
    for(int i = len - 1; i >= 1; i--)
    {
        if(str[i] == ' ')
        {
            str[newLen--] = '0';
            str[newLen--] = '2';
            str[newLen--] = '\\';
        }
        else
        {
            str[newLen--] = str[i];
        }
    }
}
