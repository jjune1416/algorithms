//
//  5-2 Double2Binary.cpp
//  CrackTheCodingInterview
//
//	0과 1사이의 실수가 double 타입의 입력으로 주어졌을 때,
//	그 값을 이진수 형태로 출력하는 코드를 작성하라.
//	길이가 32개 이하의 문자열로 출력될 수 없는 경우에는,
//	ERROR를 리턴하라.
//
//  Created by Ghost on 2018. 2. 23..
//  Copyright © 2018년 Ghost. All rights reserved.
//

#include <string>

std::string Double2Binary(double n)
{
	if(n <= 0 || n >= 1)
		return "ERROR";
	
	std::string ret = "0.";
	
	while(n >= 1e-8)
	{
		if(ret.size() >= 32)
			return "ERROR";

		n *= 2;
		if(n >= 1)
		{
			n -= 1.0;
			ret.push_back('1');
		}
		else
		{
			ret.push_back('0');
		}
	}
	
	return ret;
}