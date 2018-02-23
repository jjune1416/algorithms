//
//  2-1 DeleteDup.cpp
//  CrackTheCodingInterview
//
//  ������ unsorted ���� ����Ʈ���� �ߺ����ڸ� �����ϴ� �ڵ带 �ۼ��϶�.
//
//  Created by Ghost on 2018. 2. 14..
//  Copyright �� 2018�� Ghost. All rights reserved.
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
//  �ӽ� ���۰� ������ �ʴ� ��Ȳ���� �̹����� ��� �ذ��� �� �ְڴ°�?
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
