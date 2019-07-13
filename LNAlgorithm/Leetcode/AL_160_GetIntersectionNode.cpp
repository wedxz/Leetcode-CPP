//
//  AL_GetIntersectionNode.cpp
//  LNAlgorithm
//
//  Created by vvusu on 7/4/19.
//  Copyright © 2019 vvusu. All rights reserved.
//

#include "Algorithm.hpp"


static ListNode* getIntersectionNode(ListNode *nodeA, ListNode *nodeB)
{
    int n = ListNode::ListNodeCount(nodeA) - ListNode::ListNodeCount(nodeB);
    for (int i = 0; i < abs(n); i++) {
        if (n > 0) {
            nodeA = nodeA->next;
        } else {
            nodeB = nodeB->next;
        }
    }
    
    ListNode *p = nodeA;
    ListNode *q = nodeB;
    
    while (p && q) {
        if (p == q) {
            return q;
        } else {
            p = p->next;
            q = q->next;
        }
    }
    return NULL;
}

static void getIntersectionNode_test()
{
    ListNode listA[5] = {{0},{0},{0},{0},{0}};
    listA[0].val = 4;
    listA[0].next = &listA[1];
    listA[1].val = 1;
    listA[1].next = &listA[2];
    listA[2].val = 8;
    listA[2].next = &listA[3];
    listA[3].val = 4;
    listA[3].next = &listA[4];
    listA[4].val = 5;
    listA[4].next = NULL;
    
    
    ListNode listB[6] = {{0},{0},{0},{0},{0},{0}};
    listB[0].val = 5;
    listB[0].next = &listB[1];
    listB[1].val = 0;
    listB[1].next = &listB[2];
    listB[2].val = 1;
    listB[2].next = &listB[3];
    listB[3].val = 8;
    listB[3].next = &listB[4];
    listB[4].val = 4;
    listB[4].next = &listB[5];
    listB[5].val = 5;
    listB[5].next = NULL;
    
    ListNode::PrintListNode(getIntersectionNode(listA,listB));
    
}
