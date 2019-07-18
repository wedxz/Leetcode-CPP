//
//  AL_104_MaximumDepthOfBinaryTree.cpp
//  LNAlgorithm
//
//  Created by vvusu on 7/18/19.
//  Copyright © 2019 vvusu. All rights reserved.
//

#include "Algorithm.hpp"



// _102_二叉树的层次遍历
// https://leetcode.com/problems/maximum-depth-of-binary-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class AL_104_MaximumDepthOfBinaryTree {
public:
    int maxDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int heigh = 0;
        int level = 1;
        queue<TreeNode*> queue;
        queue.push(root);
        while (!queue.empty()) {
            TreeNode *node = queue.front();
            queue.pop();
            level--;
            if (node) {
                if (node->left) {
                    queue.push(node->left);
                }
                if (node->right) {
                    queue.push(node->right);
                }
            }
            if (level == 0) {
                level = (int)queue.size();
                heigh++;
            }
        }
        return heigh;
    }
};

