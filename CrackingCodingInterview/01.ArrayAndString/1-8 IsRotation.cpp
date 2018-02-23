//
//  1-8 IsRotation.cpp
//  CrackTheCodingInterview
//
//  한 단어가 다른 단어에 포함된 문자열인지 판별하는 isSubstring이라는 메서드가 있다고 하자.
//  s1과 s2의 두 문자열이 주어졌을 때,
//  s2가 s1을 회전시킨 결과인지 판별하는 코드를 isSubstring을 한 번만 호출하도록 작성하라.
//  (가령 'waterbottle'은 'erbottlewat'을 회전시켜 얻을 수 있는 문자열이다).
//
//  Created by Ghost on 2018. 2. 14..
//  Copyright © 2018년 Ghost. All rights reserved.
//

#include<string>

bool IsRoatation(std::string s1, std::string s2)
{
    if(s1.length() != s2.length())  return false;
    std::string s1s1 = s1 + s1;
    return s1s1.isSubstring(s2);
}
