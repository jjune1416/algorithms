//
//  17-1 Swap.cpp
//  CrackTheCodingInterview
//
//  수 하나를 이동 없이 바꾸는 함수를 작성하라.
//	(즉, 임시변수는 사용할 수 없다.)
//
//  Created by Ghost on 2018. 2. 22..
//  Copyright © 2018년 Ghost. All rights reserved.
//

void Swap1(int& a, int& b)
{
	a = a - b; // a = a - b
	b = a + b ; // b = a
	a = b - a;
}


void Swap2(int& a, int& b)
{
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
}