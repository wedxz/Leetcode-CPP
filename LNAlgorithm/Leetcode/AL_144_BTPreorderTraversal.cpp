//
//  AL_144_BTPreorderTraversal.cpp
//  LNAlgorithm
//
//  Created by vvusu on 7/16/19.
//  Copyright © 2019 vvusu. All rights reserved.
//

#include "Algorithm.hpp"


// _144_二叉树的前序遍历
// https://leetcode.com/problems/binary-tree-preorder-traversal/


class AL_144_BTPreorderTraversal {
public:
    // 1
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> v;
        preorderTreeNode(root, v);
        return v;
    }
    
    void preorderTreeNode(TreeNode* root, vector<int> &v) {
        if (root == NULL) return;
        v.push_back(root->val);
        preorderTreeNode(root->left, v);
        preorderTreeNode(root->right, v);
    }
    
    // 2
    vector<int> preorderTraversal2(TreeNode* root) {
        vector<int> v;
        stack<TreeNode *> s;
        TreeNode *cur = root;
        while (cur || !s.empty()) {
            if (cur) {
                v.push_back(cur->val);
                s.push(cur);
                cur = cur->left;
            } else {
                cur = s.top();
                s.pop();
                cur = cur->right;
            }
        }
        return v;
    }
};
