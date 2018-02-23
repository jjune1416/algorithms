//
//  4-1 IsBalancedTree.cpp
//  CrackTheCodingInterview
//
//  주어진 이진 트리가 균형 이진 트리인지 판별하는 함수를 구현하라.
//  이 문제에서 이진 트리는 어떤 노드의 두 자식 트리 깊이가 하나 이상 차이나지 않는 트리다.
//
//  Created by Ghost on 2018. 2. 22..
//  Copyright © 2018년 Ghost. All rights reserved.
//

#include <cmath>
#include <algorithm>

struct Node
{
    int val;
    Node* left;
    Node* right;
    
    Node()
    {
        val = 0;
        left = 0;
        right = 0;
    }
};

int GetHeight(Node* head)
{
    if(head == 0)   return 0;
    
    int leftHeight = GetHeight(head -> left);
    int rightHeight = GetHeight(head -> right);
    
    if(std::abs(leftHeight - rightHeight) > 1)  return -1;
    
    return std::max(leftHeight, rightHeight) + 1;
}

bool IsBalancedTree(Node* head)
{
    return GetHeight(head) != -1;
}
