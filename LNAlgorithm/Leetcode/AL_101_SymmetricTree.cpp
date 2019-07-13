//
//  AL_SymmetricTree.cpp
//  LNAlgorithm
//
//  Created by vvusu on 6/27/19.
//  Copyright © 2019 vvusu. All rights reserved.
//

#include "Algorithm.hpp"

/*
 LeetCode 101
 Symmetric Tree （是否是镜像树）
 */

static bool checkLeftAndRightNodes(TreeNode *left, TreeNode *right)
{
    if (left == NULL && right == NULL) {
        return true;
    }
    if (left == NULL || right == NULL) {
        return false;
    }
    if (left->val != right->val) {
        return false;
    } else {
        return checkLeftAndRightNodes(left->left, right->right) && checkLeftAndRightNodes(left->right, right->left);
    }
    
}

static bool symmetricTree(TreeNode *root)
{
    if (root == NULL) {
        return true;
    }
    return checkLeftAndRightNodes(root->left, root->right);
}

static void symmetricTree_test()
{
}
