//
//  1-1 UniqueCharater.cpp
//  CrackTheCodingInterview
//
//  문자열에 포함된 문자들이 전부 유일한지를 검사하는 알고리즘을 구현하라.
//  다른 자료구조를 사용할 수 없는 상황이라면 어떻게 하겠는가?
//
//  Created by Ghost on 2018. 1. 28..
//  Copyright © 2018년 Ghost. All rights reserved.
//
//  - ASCII 인지 확인 필요

#include <string>

const int UNI_SIZE = 256;
bool aqufied[UNI_SIZE];

bool IsUniqueChars(std::string str)
{
    if(str.size() > UNI_SIZE) return false;
    for(int i = 0;i < UNI_SIZE ; i++)
        aqufied[i] = false;
    for(int i = 0 ;i < str.size(); i++)
    {
        int index = str[i];
        if(aqufied[index]) return false;
        aqufied[index] = true;
    }
    return true;
}
