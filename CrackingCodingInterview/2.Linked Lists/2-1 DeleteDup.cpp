//
//  2-1 DeleteDup.cpp
//  CrackTheCodingInterview
//
//  비정렬 unsorted 연결 리스트에서 중복문자를 제거하는 코드를 작성하라.
//
//  Created by Ghost on 2018. 2. 14..
//  Copyright ⓒ 2018년 Ghost. All rights reserved.
//

#include <iostream>

struct node
{
    char c;
    node* next;
};

void DeleteDup(node* head)
{
    node* prev = 0;
    node* next = head;
    bool hashTable[256] = {false, };
    
    while(next != 0)
    {
        if(hashTable[(next->c + 256) % 256])
        {
            prev->next = next = next->next;
        }
	    else
	    {
		    hashTable[(next->c + 256) % 256] = true;
            prev = next;
            next = next->next;
	    }
    }
}

//
//  임시 버퍼가 허용되지 않는 상황에서 이문제를 어떻게 해결할 수 있겠는가?
//

void DeleteDupNoBuf(node* head)
{
    node* curr = head;
    
    while(curr != 0)
    {
        node* prev = curr;
        node* next = curr -> next;
        while(next != 0)
        {
            if(next -> c == curr -> c)
            {
                prev->next = next = next->next;
            }
    	    else
    	    {
                prev = next;
                next = next->next;
    	    }
        }
        curr = curr -> next;
    }
}
