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
    
}
