//
//  AL_83_DeleteDuplicates.cpp
//  LNAlgorithm
//
//  Created by vvusu on 7/4/19.
//  Copyright © 2019 vvusu. All rights reserved.
//

#include "Algorithm.hpp"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

static ListNode* deleteDuplicates(ListNode* head) {
    ListNode* nextNode = head->next;
    head->val = nextNode->val;
    head->next = nextNode->next;
    delete nextNode;
    return NULL;
}
