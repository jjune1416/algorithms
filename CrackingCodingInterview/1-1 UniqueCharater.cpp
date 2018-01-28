//
//  1-1 UniqueCharater.cpp
//  CrackTheCodingInterview
//
//  Created by Ghost on 2018. 1. 28..
//  Copyright © 2018년 Ghost. All rights reserved.
//

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
