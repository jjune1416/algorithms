//
//  KthNumber.cpp
//  1 - N 까지의 숫자를 쓴다.
//  12345678910111213141516....9991000
//  1. M 번째에 나오는 숫자는 무엇인가.
//  2. N 까지의 숫자에서 0이 몇개 등장하는가?
//
//  Created by Ghost on 2018. 4. 22..
//  Copyright © 2018년 Ghost. All rights reserved.
//

#include <iostream>
#include <string>
#include <ctime>
#include <cmath>

int NumberOfN(int n)
{
    int i = 0;
    while(n)
    {
        n /= 10;
        i++;
    }
    return i;
}

int MthNumberInSingle(int baseNumber, int M)
{
    std::string temp = std::to_string(baseNumber);
    return (int)temp[M - 1] -  '0';
}

long long int  NumberOfSetN(int i)
{
    return 9 * i * pow(10, i - 1);
}

int MthNumberNew(long long int m)
{
    long long int count = 0;
    int preCalc = 1;
    for(int i = 1;;i++)
    {
        if(count + NumberOfSetN(i) >= m)
        {
            break;
        }
        preCalc *= 10;
        count += NumberOfSetN(i);
    }
    
    for(int i = preCalc; ; i++)
    {
        if(count + NumberOfN(i) >= m)
        {
            return (int)MthNumberNew(i, m - count);
        }
        count += NumberOfN(i);
    }
    
    return -1; // err
}

int MthNumberOld(int m)
{
    int count = 0;
    for(int i = 1; ; i++)
    {
        if(count + NumberOfN(i) >= m)
        {
            return MthNumberNew(i, m - count);
        }
        count += NumberOfN(i);
    }
    
    return -1; // err
}

int main()
{
    int M, N;
    std::cin >> M >> N;
    std::clock_t start = std::clock();
    std::cout << MthNumberOld(M) << std::endl;
    std::cout << "time : " << std::clock() - start << std::endl;
    start = std::clock();
    std::cout << MthNumberNew(M) << std::endl;
    std::cout << "time : " << std::clock() - start << std::endl;
    return 0;
}
