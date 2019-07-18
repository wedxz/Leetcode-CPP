//
//  AL_BalancedTree.cpp
//  LNAlgorithm
//
//  Created by vvusu on 6/27/19.
//  Copyright © 2019 vvusu. All rights reserved.
//

#include "Algorithm.hpp"

/*
 LeetCode 110
 Balanced Binary Tree (是否是平衡二叉树)
*/

static int heightDepthTree(TreeNode *root)
{
    if (root == NULL) {
        return 0;
    }
    int l = heightDepthTree(root->left);
    int r = heightDepthTree(root->right);
    return l > r ? l+1 : r+1;
}


static bool balancedTree(TreeNode *root)
{
    if (root == NULL) {
        return true;
    } else {
        int l , r;
        l = heightDepthTree(root->left);
        r = heightDepthTree(root->right);
        if (l > r + 1 || r > l + 1) {
            return false;
        } else {
            return (balancedTree(root->left) && balancedTree(root->right));
        }
    }
}
