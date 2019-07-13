//
//  AL_ InvertTree.cpp
//  LNAlgorithm
//
//  Created by vvusu on 6/27/19.
//  Copyright © 2019 vvusu. All rights reserved.
//

#include "Algorithm.hpp"

/*
 LeetCode 226  反转二叉树
 
 */

static TreeNode *invertTree(TreeNode *root)
{
    if (root == NULL) {
        return NULL;
    }
    TreeNode *tempNode = root->left;
    root->left         = root->right;
    root->right        = tempNode;
    
    invertTree(root->left);
    invertTree(root->right);
    return root;
}

static void invertTree_test()
{
}
