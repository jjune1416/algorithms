//
//  1-5 CompressBad.cpp
//  CrackTheCodingInterview
//
//  같은 문자가 연속으로 반복될 경우, 그 횟수를 사용해 문자열을 압축하는 메서드를 구현하라.
//  가령 압축해야 할 문자열이 aabccccccccaaa라면 a2b1c8a3과 같이 압축되어야 한다.
//  압축 결과로 만들어지는 문자열이 원래 문자열보다 짧아지지 않는경우,
//  이 메서드는 원래 문자열을 그대로 반환해야한다.
//
//  Created by Ghost on 2018. 1. 28..
//  Copyright © 2018년 Ghost. All rights reserved.
//

#include <string>

std::string CompressBad(std::string src)
{
    if (src.empty())    return src;
    std::string convert;
    
    int count = 1;
    char prev = src[0];
    for(int i = 1 ;i < src.length();i++)
    {
        if(prev != src[i])
        {
            convert.push_back(prev);
            convert += std::to_string(count);
            prev = src[i];
            count = 1;
        }
        else
        {
            count++;
        }
    }
    
    return (convert.size() < src.size() ? src : convert);
}
