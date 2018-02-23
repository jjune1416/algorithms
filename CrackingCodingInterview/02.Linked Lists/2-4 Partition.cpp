//
//  2-4 Partition.cpp
//  CrackTheCodingInterview
//
//  x값을 갖는 노드를 기준으로 연겨 리스트를 나누는 코드를 작성하라.
//  x보다 작은 값을 갖는 노드가 x와 같거나 더 큰 값을 갖는 노드들 보다 앞쪽에 오도록 하면 된다.
//
//  Created by Ghost on 2018. 2. 18..
//  Copyright © 2018년 Ghost. All rights reserved.
//

struct LinkedListNode
{
    int value;
    LinkedListNode* next;
};

LinkedListNode* InsertNode(LinkedListNode* head, LinkedListNode *newNode)
{
    newNode -> next = head;
    head = newNode;
    return head;
}

LinkedListNode* Partition(LinkedListNode* head, int pivot)
{
    LinkedListNode *leftHead = 0;
    LinkedListNode *rightHead = 0;
    
    LinkedListNode *node = head;
    
    while(node)
    {
        LinkedListNode* next = node -> next;
        if(node -> value < pivot)
            leftHead = InsertNode(leftHead, node);
        else
            rightHead = InsertNode(rightHead, node);
        node = next;
    }
    
    if(leftHead == 0)
        return rightHead;
    
    LinkedListNode *leftTail = leftHead;
    while(leftTail -> next)
        leftTail = leftTail -> next;
    leftTail -> next = rightHead;
    
    return leftHead;
}
