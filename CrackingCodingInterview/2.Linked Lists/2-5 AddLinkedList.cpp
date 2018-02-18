//
//  2-5 AddLinkedList.cpp
//  CrackTheCodingInterview
//
//  연결 리스트로 표현된 두개의 수가 있다고 하자.
//  리스트의 각 노드는 해당 수의 각 자릿수를 표현한다.
//  이때 자릿수들은 역순으로 배열되는데,
//  1의 자릿수가 리스트의 맨 앞에 오도록 배열된다는 뜻이다.
//  이 두 수를 더하여 그 합을 연결 리스트로 반환하는 함수를 작성하라.
//
//  Created by Ghost on 2018. 2. 18..
//  Copyright © 2018년 Ghost. All rights reserved.
//

struct LinkedListNode
{
    int value;
    LinkedListNode* next;
};

LinkedListNode *AddLinkedList(LinkedListNode *leftHead, LinkedListNode *rightHead, int carry)
{
    if(leftHead == 0 && rightHead == 0 && carry == 0)
        return 0;
    
    int leftValue = leftHead ? leftHead -> value : 0;
    int rightValue = rightHead ? rightHead -> value : 0;
    
    int sum = leftValue + rightValue + carry;
    
    LinkedListNode *head = new LinkedListNode;
    head -> value = sum % 10;
    
    LinkedListNode *leftNext = leftHead ? leftHead -> next : 0;
    LinkedListNode *rightNext = rightHead ? rightHead -> next : 0;
    head -> next = AddLinkedList(leftNext, rightNext, sum/10);
    
    return head;
}

//
//  각 자릿수가 정상적으로 배열된다고 가정하고 구현해 보자.
//
int GetListLength(LinkedListNode *head)
{
    if(head)
        return 1 + GetListLength(head -> next);
    return 0;
}

LinkedListNode *PadZero(LinkedListNode *head, int count)
{
    if(count <= 0)  return head;
    LinkedListNode* pad = new LinkedListNode;
    pad -> value = 0;
    pad -> next = PadZero(head, count - 1);
    return pad;
}

LinkedListNode *_AddLinkedListSeq(LinkedListNode *leftHead, LinkedListNode *rightHead, int& carry)
{
    if(leftHead == 0 || rightHead == 0) return 0;
    int newCarry;
    LinkedListNode* head = new LinkedListNode;
    head -> next = _AddLinkedListSeq(leftHead -> next, rightHead -> next, newCarry);
    int sum = leftHead -> value + rightHead -> value + newCarry;
    head -> value = sum % 10;
    carry = sum / 10;
    return head;
}

LinkedListNode *AddLinkedListSeq(LinkedListNode *leftHead, LinkedListNode *rightHead)
{
    if(leftHead == 0 && rightHead == 0)
        return 0;
    
    int leftLen = GetListLength(leftHead);
    int rightLen = GetListLength(rightHead);
    
    leftHead = PadZero(leftHead, rightLen - leftLen);
    leftHead = PadZero(leftHead, 1);
    rightHead = PadZero(rightHead, leftLen -  rightLen);
    rightHead = PadZero(rightHead, 1);

    int carry;
    LinkedListNode *head = _AddLinkedListSeq(leftHead, rightHead, carry);
     
    return head -> value ? head : head -> next;
}
