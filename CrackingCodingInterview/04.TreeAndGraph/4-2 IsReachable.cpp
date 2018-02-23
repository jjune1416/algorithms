//
//  4-2 IsReachable.cpp
//  CrackTheCodingInterview
//
//  주어진 유향 그래프(directed graph)에서 특정한 두 노드 간에
//  경로(route)가 존재하는지를 판별하는 알고리즘을 구현하라.
//
//  Created by Ghost on 2018. 2. 22..
//  Copyright © 2018년 Ghost. All rights reserved.
//

#include <vector>
#include <queue>

struct Node
{
    bool visit;
    std::vector<Node*> adjNode;
};

bool IsReachable(Node* start, Node* end, std::vector<Node*> graph)
{
    for(auto node : graph)
        node -> visit = false;
    
    std::queue<Node *> q;
    start->visit = true;
    q.push(start);
    
    while(!q.empty())
    {
        Node* curr = q.back();
        q.pop();
        
        if(curr == end) return true;
        else if(curr == 0)  continue;
        
        for(int i = 0 ;i < curr->adjNode.size(); i++)
        {
            Node* next = curr->adjNode.at(i);
            if(next -> visit == false)
            {
                next -> visit = true;
                q.push(next);
            }
        }
    }
    return false;
}
