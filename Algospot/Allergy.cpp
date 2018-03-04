//
//  Allergy
//  https://algospot.com/judge/problem/read/ALLERGY
//
//  Created by Ghost on 2018. 3. 4..
//  Copyright © 2018년 Ghost. All rights reserved.
//

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <map>

const int MAX = 20;

struct _food
{
    int count;
    std::vector<int> person;
    
    bool operator>(const _food& rhs) const
    {
        return count > rhs.count;
    }
};

int n, m;
int candidate;
int eaten[MAX];
std::vector<_food> food;
std::map< std::string, int > mapNames;

void init()
{
    candidate = MAX;
    food.clear();
    mapNames.clear();
    for(int i = 0 ; i < MAX ;i++)
        eaten[i] = 0;
}

void input()
{
    std::cin >> n >> m ;
    for(int i = 0; i < n; i++)
    {
        std::string buf;
        std::cin >> buf;
        mapNames[buf] = i;
    }
    for(int i = 0 ;i < m; i++)
    {
        _food f;
        std::cin >> f.count;
        for(int j = 0 ;j < f.count ; j++)
        {
            std::string buf;
            std::cin >> buf;
            auto it = mapNames.find(buf);
            f.person.push_back(it -> second);
        }
        food.push_back(f);
    }
    std::sort(food.begin(), food.end(), std::greater<_food>());
    
    for(int i = 0 ;i < food.size(); i++)
    {
        std::vector<int>& biggerOne = food[i].person;
        for(int j = i + 1; j < food.size() ;)
        {
            bool include = true;
            for(int person : food[j].person)
            {
                if(std::find(biggerOne.begin(), biggerOne.end(), person) == biggerOne.end())
                {
                    include = false;
                    break;
                }
            }
            
            if(include)
                food.erase(food.begin() + j);
            else
                j++;
        }
    }
}

void MinFoodCount(int depth, int takenFood, int hungryPerson)
{
    if(hungryPerson == 0)
    {
        candidate = std::min(candidate, takenFood);
        return;
    }
    if(depth >= food.size())          return;
    
    /*
    int minimumFood = 0;
    int maximumPerson = 0;
    for(int i = depth; i < food.size() && maximumPerson >= hungryPerson; i++)
    {
        minimumFood++;
        maximumPerson += food[i].count;
        
    }
    if(candidate <= takenFood + minimumFood)    return;
     */
    if(candidate <= takenFood + 1)    return;
    
    MinFoodCount(depth + 1, takenFood, hungryPerson);
    
    _food& target = food[depth];
    bool cont = false;
    for(int& person : target.person)
    {
        if(eaten[person] == 0)
        {
            cont = true;
            break;
        }
    }
    if(!cont)   return;
    
    for(int person : target.person)
    {
        if(eaten[person] == 0)
            hungryPerson--;
        eaten[person]++;
    }
    MinFoodCount(depth + 1, takenFood + 1, hungryPerson);
    for(int person : target.person)
        eaten[person]--;
}

int main()
{
    int TC;
    std::cin >> TC;
    while(TC--)
    {
        init();
        input();
        MinFoodCount(0, 0, n);
        std::cout << candidate << std::endl;
    }
    
    return 0;
}
