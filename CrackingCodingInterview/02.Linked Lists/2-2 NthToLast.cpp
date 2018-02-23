//
//  2-2 NthToLast.cpp
//  CrackTheCodingInterview
//
//  단방향 연결리스트에서, 뒤에서 k번째 원소를 찾는 알고리즘을 구현하라.
//
//  Created by Ghost on 2018. 2. 18..
//  Copyright © 2018년 Ghost. All rights reserved.
//

//  node를 반환할지, value를 반환할지 확인 필요.

struct LinkedListNode
{
    int value;
    LinkedListNode* next;
};

int GetLength(LinkedListNode* head)
{
    if(head != 0)
        return 1 + GetLength(head->next);
    return 0;
}

// O(2n)
LinkedListNode * NthToLast1(LinkedListNode* head, int N)
{
    int length = GetLength(head);
    
    if(length < N)
        return 0;
    
    LinkedListNode *pNode = head;
    while(--N)
        pNode = pNode -> next;
    
    return pNode;
}

// O(n)
LinkedListNode * NthToLast2(LinkedListNode* head, int N)
{
    if(head == 0)
        return 0;
    
    if(N == 1)
        return head;
    return NthToLast2(head->next, N - 1);
}
