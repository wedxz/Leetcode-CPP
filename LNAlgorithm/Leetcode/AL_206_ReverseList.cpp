//
//  AL_206_ReverseList.cpp
//  LNAlgorithm
//
//  Created by vvusu on 7/13/19.
//  Copyright © 2019 vvusu. All rights reserved.
//

#include "Algorithm.hpp"

// 206. Reverse Linked List
// https://leetcode.com/problems/reverse-linked-list/

class AL_206_ReverseList {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode *newHead = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return newHead;
    }
    
    ListNode* reverseList2(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode *newHead = NULL;
        while (head != NULL) {
            ListNode *tmp = head->next;
            head->next = newHead;
            newHead = head;
            head = tmp;
        }
        return head;
    }
};
