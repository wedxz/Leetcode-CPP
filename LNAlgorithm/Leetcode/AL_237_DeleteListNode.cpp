//
//  AL_237_DeleteListNode.cpp
//  LNAlgorithm
//
//  Created by vvusu on 7/13/19.
//  Copyright © 2019 vvusu. All rights reserved.
//

#include "Algorithm.hpp"

// 237. 删除链表中的节点
// https://leetcode.com/problems/delete-node-in-a-linked-list/

class AL_237_DeleteListNode {
public:
    void deleteNode(ListNode* node) {
        ListNode *nextNode = node->next;
        node->val = nextNode->val;
        node->next = nextNode->next;
        delete nextNode;
    }
};
