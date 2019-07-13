//
//  AL_203_RemoveElements.cpp
//  LNAlgorithm
//
//  Created by vvusu on 7/4/19.
//  Copyright © 2019 vvusu. All rights reserved.
//

#include "Algorithm.hpp"


/**
 https://leetcode.com/problems/remove-linked-list-elements/
 Input:  1->2->6->3->4->5->6, val = 6
 Output: 1->2->3->4->5
 */

static ListNode* removeElements(ListNode* head, int val) {
    if (head == NULL) { return NULL; }
    ListNode* temp = head;
    while (temp->next != NULL) {
        if (temp->next->val == val) {
            temp->next = temp->next->next;
        } else {
            temp = temp->next;
        }
    }
    if (head->val == val) {
        head = head->next;
    }
    return head;
}

static void removeElements_test()
{
    ListNode list[7] = {{0},{0},{0},{0},{0},{0},{0}};
    list[0].val = 1;
    list[0].next = &list[1];
    list[1].val = 2;
    list[1].next = &list[2];
    list[2].val = 6;
    list[2].next = &list[3];
    list[3].val = 3;
    list[3].next = &list[4];
    list[4].val = 4;
    list[4].next = &list[5];
    list[5].val = 5;
    list[5].next = &list[6];
    list[6].val = 6;
    list[6].next = NULL;
    ListNode::PrintListNode(removeElements(list, 6));
}
