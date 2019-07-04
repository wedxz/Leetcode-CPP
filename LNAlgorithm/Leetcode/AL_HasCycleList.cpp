//
//  AL_ HasCycleList.cpp
//  LNAlgorithm
//
//  Created by vvusu on 6/28/19.
//  Copyright © 2019 vvusu. All rights reserved.
//

#include "Algorithm.hpp"

/*
 LeetCode 141
 Linked List Cycle (链表是否有环)
 */

static bool hasCycleList(ListNode *list)
{
    ListNode *slow = list;
    ListNode *fast = list;
    
    while (slow != NULL && fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            return true;
        }
    }
    return false;
}

static void hasCycleList_test()
{
    
}
