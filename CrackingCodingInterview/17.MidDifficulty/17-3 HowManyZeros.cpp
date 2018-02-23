//
//  17-3 HowManyZeros.cpp
//  CrackTheCodingInterview
//
//	n!의 계산 결과로 구해진 값의 마지막에 붙은 연속된 0의 개수를 계산하는 알고리즘을 작성하라.
//
//  Created by Ghost on 2018. 2. 23..
//  Copyright © 2018년 Ghost. All rights reserved.
//

int HowManyZeros(int n)
{
	int count = 0;
	for(int i = 5; i < n ; i *= 5)
		count += n / i;
	return count;
}