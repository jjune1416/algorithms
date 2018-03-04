//
//  BoardCover2.cpp
//  https://algospot.com/judge/problem/read/BOARDCOVER2
//
//  Created by Ghost on 2018. 3. 3..
//  Copyright © 2018년 Ghost. All rights reserved.
//

#include <vector>
#include <iostream>
#include <algorithm>

const int MAX_SIZE = 10;

char grid[MAX_SIZE][MAX_SIZE+1];
char cover[MAX_SIZE][MAX_SIZE+1];
std::vector< std::vector< std::pair<int, int> > > rotates;
int max;
int H, W, R, C;

void MakeCover()
{
    rotates.clear();
    std::vector< std::pair<int, int> > r;
    for(int y = 0 ; y < R; y++)
        for(int x = 0 ; x < C; x++)
            if(cover[y][x] == '#')
               r.push_back(std::make_pair(y, x));
    rotates.push_back(r);
    
    for(int i = 1; i < 4; i++)
    {
        auto prev = rotates[i - 1];
     
        std::vector< std::pair<int, int> > buf;
        for(auto it = prev.begin(); it != prev.end() ; it++)
        {
            int y = it->first;
            int x = it->second;
            buf.push_back(std::make_pair((i % 2 ? C : R) - x - 1, y));
        }
        rotates.push_back(buf);
    }
    
    for(int i = 0 ;i < rotates.size(); i++)
    {
        auto& curr = rotates[i];
        
        int leftTop = 101;
        for(auto it = curr.begin(); it != curr.end() ; it++)
            leftTop = std::min(leftTop, 10 * it->first + it->second);
        
        for(int i = 0 ;i < curr.size(); i++)
        {
            auto& item = curr[i];
            item.first -= leftTop / 10;
            item.second -= leftTop % 10;
        }
    }
    
    std::sort(rotates.begin(), rotates.end());
    rotates.erase(std::unique(rotates.begin(), rotates.end()), rotates.end());
}

inline bool IsEmptyCell(int y, int x)
{
    return !(y < 0 || y >= H || x < 0 || x >= W || grid[y][x] == '#');
}

bool IsFillable(int y, int x, int rotate)
{
    bool isFillable = true;
    for(auto it = rotates[rotate].begin(); it != rotates[rotate].end() && isFillable ; it++)
        isFillable = IsEmptyCell(y + it->first, x + it->second);
    return isFillable;
}

void FillGrid(int y, int x, int rotate, char coverType)
{
    for(auto it = rotates[rotate].begin(); it != rotates[rotate].end() ; it++)
        grid[y + it->first][x + it->second] = coverType;
}

void MaxCoverCount(int index, int covered, int leftCellCount, int coverCellCount)
{
    max = std::max(max,covered);
    
    if(index >= H * W)  return;
    if(max >= covered + leftCellCount / coverCellCount)    return;
    
    int y = index / W;
    int x = index % W;
    while(grid[y][x] == '#')
    {
        index++;
        y = index / W;
        x = index % W;
    }

    for(int rotate = 0 ; rotate < rotates.size(); rotate++)
    {
        if(IsFillable(y, x, rotate))
        {
            FillGrid(y, x, rotate, '#');
            MaxCoverCount(index + 1, covered + 1, leftCellCount - coverCellCount, coverCellCount);
            FillGrid(y, x, rotate, '.');
        }
    }
    MaxCoverCount(index + 1, covered, leftCellCount - 1, coverCellCount);
}

int main()
{
    int TC;
    std::cin >> TC;
    while(TC--)
    {
        std::cin >> H >> W >> R >> C;
        for(int i = 0; i < H; i++)
            std::cin >> grid[i];
        for(int i = 0; i < R; i++)
            std::cin >> cover[i];
        int leftCellCount = 0;
        for(int y = 0 ; y < H; y++)
            for(int x = 0; x < W; x++)
                leftCellCount += (grid[y][x] == '.');
        int coverCellCount = 0;
        for(int y = 0 ; y < R; y++)
            for(int x = 0; x < C; x++)
                coverCellCount += (cover[y][x] == '#');
        
        MakeCover();
        max = 0;
        MaxCoverCount(0, 0, leftCellCount, coverCellCount);
        std::cout << max << std::endl;
    }
    return 0;
}
