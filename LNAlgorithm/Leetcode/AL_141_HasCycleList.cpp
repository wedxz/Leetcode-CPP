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
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            return true;
        }
    }
    return false;
}

static void hasCycleList_test()
{
    ListNode list[4] = {{0},{0},{0},{0}};
    list[0].val = 1;
    list[0].next = &list[1];
    list[1].val = 2;
    list[1].next = &list[2];
    list[2].val = 3;
    list[2].next = &list[3];
    list[3].val = 4;
    list[3].next = &list[2];;
    
   cout << "链表是否有环：" << hasCycleList(list) << endl;
}
