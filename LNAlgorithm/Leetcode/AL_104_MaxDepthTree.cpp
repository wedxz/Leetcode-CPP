//
//  AL_ MaxDepthTree.cpp
//  LNAlgorithm
//
//  Created by vvusu on 6/27/19.
//  Copyright © 2019 vvusu. All rights reserved.
//

#include "Algorithm.hpp"

/*
 LeetCode 104
 Maximum Depth of Binary Tree (二叉树的深度)
 
 */

static int maxDepthTree(TreeNode *root)
{
    if (root == NULL) {
        return 0;
    }
    int l = maxDepthTree(root->left);
    int r = maxDepthTree(root->right);
    return l > r ? l + 1 : r + 1;
}
