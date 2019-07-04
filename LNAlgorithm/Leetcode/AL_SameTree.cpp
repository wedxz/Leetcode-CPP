//
//  AL_SameTree.cpp
//  LNAlgorithm
//
//  Created by vvusu on 6/27/19.
//  Copyright © 2019 vvusu. All rights reserved.
//

#include "Algorithm.hpp"

/*
 LeetCode 100  https://leetcode.com/problems/same-tree/
 Is Same Tree (两个树是否相等)
 */

static bool sameTree(TreeNode *p, TreeNode *q)
{
    if (p == NULL && q != NULL) {
        return false;
    }
    else if (p != NULL && q == NULL)
    {
        return false;
    }
    else if (p == NULL && q == NULL)
    {
        return true;
    }
    else if ((p != NULL && q != NULL) && (p->val != q->val))
    {
        return false;
    }
    else
    {
        return sameTree(p->left, q->left) && sameTree(p->right, q->right);
    }
}

static void sameTree_test()
{
}
