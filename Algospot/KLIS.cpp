//
//  KLIS.cpp
//  https://algospot.com/judge/problem/read/KLIS
//
//  Created by Ghost on 2018. 2. 4..
//  Copyright © 2018년 Ghost. All rights reserved.
//

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

const int MAX_LEN = 501;
const long long INF = 0x7FFFFFFF;

int length;
int arr[MAX_LEN];
int memoLIS[MAX_LEN];
int memoCLIS[MAX_LEN];

struct item_count
{
    int index;
    int value;
    int count;
    item_count(int in, int va, int c):index(in),value(va),count(c){};
};

bool operator<(const item_count& lhs, const item_count& rhs)
{
    return lhs.value < rhs.value;
}

int LIS(int index)
{
    if(index < 0 || index > length)     return 0;
    int& ret = memoLIS[index];
    if(ret != -1) return ret;
    int max = 0;
    for(int i = index + 1 ; i <= length ; i++)
        if(arr[i] > arr[index])
            max = std::max(LIS(i), max);
    return ret = max + 1;
}

int HowManyLIS(int index)
{
    if(index < 0 || index > length)     return 0;
    int& ret = memoCLIS[index];
    if(ret != -1)   return ret;
    if(LIS(index) == 1) return ret = 1;
    ret = 0;
    int max = 0;
    for(int i = index + 1 ;i <= length ; i++)
    {
        if(arr[i] > arr[index])
        {
            int buf = LIS(i);
            if (buf > max)
            {
                max = buf;
                ret = HowManyLIS(i);
            }
            else if(buf == max)
            {
                ret = std::min<long long>(INF, (long long)ret +  HowManyLIS(i));
            }
        }
    }
    return ret;
}

std::string KLIS(int index, int lisLen, int k)
{
    if(lisLen == 1)    return std::to_string(arr[index]);
    
    std::vector<item_count> counts;
    for(int i = index + 1; i <= length ; i++)
        if(arr[i] > arr[index] && LIS(i) == lisLen - 1)
            counts.push_back(item_count(i, arr[i], HowManyLIS(i)));
    
    std::sort(counts.begin(), counts.end());
    int next;
    for(next = 0 ;next < counts.size(); next++)
    {
        if(counts[next].count > k) break;
        k -= counts[next].count;
    }
    return std::to_string(arr[index]) + " " + KLIS(counts[next].index, lisLen - 1, k);
}

int main()
{
    int TC;
    std::cin >> TC;
    while(TC--)
    {
        int k, lis;
        std::cin >> length >> k;
        arr[0] = memoLIS[0] = memoCLIS[0] = -1;
        for(int i = 1 ;i <= length; i++)
        {
            std::cin >> arr[i];
            memoLIS[i] = memoCLIS[i] = -1;
        }
        lis = LIS(0);
        std::string klis = KLIS(0, lis, k - 1);
        std::cout << lis - 1 << std::endl;
        std::cout << klis.substr(3) << std::endl;
    }
    return 0;
}
