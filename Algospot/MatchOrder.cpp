//
//  MatchOrder.cpp
//  https://algospot.com/judge/problem/read/MATCHORDER
//
//  Created by Ghost on 2018. 2. 9..
//  Copyright © 2018년 Ghost. All rights reserved.
//

#include <iostream>
#include <algorithm>

const int MAX = 100;

int ourRatings[MAX];
int theirRatings[MAX];

int GetMaxWins(int theirRatings[], int ourRatings[], int numberOfMatch)
{
	std::sort(theirRatings, theirRatings + numberOfMatch, std::greater<int>());
	std::sort(ourRatings, ourRatings + numberOfMatch, std::greater<int>());
	
	int theirPivot = 0;
	int ourPivot = 0;
	
	int ret = 0;
	while(theirPivot < numberOfMatch && ourPivot < numberOfMatch)
	{
		if(ourRatings[ourPivot] >= theirRatings[theirPivot])
		{
			ret++;
			ourPivot++;
		}
		theirPivot++;
	}
	return ret;
}

int main()
{
    int TC;
    std::cin >> TC;
    while(TC--)
    {
		int numberOfMatch;
        std::cin >> numberOfMatch;
		for(int i = 0 ; i < numberOfMatch ; i++)
			std::cin >> theirRatings[i];
		for(int i = 0 ; i < numberOfMatch ; i++)
			std::cin >> ourRatings[i];
        std::cout << GetMaxWins(theirRatings, ourRatings, numberOfMatch) << std::endl;
    }
    return 0;
}
