//
//  AL_83_DeleteDuplicates.cpp
//  LNAlgorithm
//
//  Created by vvusu on 7/4/19.
//  Copyright © 2019 vvusu. All rights reserved.
//

#include "Algorithm.hpp"

/**
 83. 删除排序链表中的重复元素
 https://leetcode.com/problems/remove-duplicates-from-sorted-list/submissions/
 
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

static ListNode* deleteDuplicates(ListNode* head) {
    if (head == NULL) { return NULL; }
    ListNode* temp = head;
    unordered_map<int, int> m;
    while (temp->next != NULL) {
        if (m.count(temp->next->val)) {
            temp->next = temp->next->next;
        } else {
            m[temp->next->val] = 0;
            temp = temp->next;
        }
    }
    if (m.count(head->val)) {
        head = head->next;
    }
    return head;
}
