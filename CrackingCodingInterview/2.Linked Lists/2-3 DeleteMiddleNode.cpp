//
//  2-3 DeleteMiddleNode.cpp
//  CrackTheCodingInterview
//
//  단방향 연결리스트의 중간에 있는 노드 하나를 삭제하는 알고리즘을 구현하라.
//  삭제할 노드에 대한 접근만 가능하다는 것에 유의하라.
//
//  Created by Ghost on 2018. 2. 18..
//  Copyright © 2018년 Ghost. All rights reserved.
//


struct LinkedListNode
{
    int value;
    LinkedListNode* next;
};

void DeleteMiddleNode(LinkedListNode *node)
{
    // 예외 처리는 필수.
    if(node == 0 || node -> next == 0)   return;
    
    LinkedListNode* buf = node -> next;
    
    node -> value = buf -> value;
    node -> next = buf -> next;
    
    delete buf;
}
