//
//  AL_94_ BTInorderTraversal.cpp
//  LNAlgorithm
//
//  Created by vvusu on 7/17/19.
//  Copyright © 2019 vvusu. All rights reserved.
//

#include "Algorithm.hpp"


// _94_二叉树的中序遍历
// https://leetcode.com/problems/binary-tree-inorder-traversal/


class AL_94_BTInorderTraversal {
public:
    // 1
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> v;
        preorderTreeNode(root, v);
        return v;
    }
    
    void preorderTreeNode(TreeNode* root, vector<int> &v) {
        if (root == NULL) return;
        preorderTreeNode(root->left, v);
        v.push_back(root->val);
        preorderTreeNode(root->right, v);
    }
    
    // 2
    vector<int> preorderTraversal2(TreeNode* root) {
        vector<int> v;
        stack<TreeNode *> s;
        TreeNode *cur = root;
        while (cur || !s.empty()) {
            if (cur) {
                s.push(cur);
                cur = cur->left;
            } else {
                cur = s.top();
                s.pop();
                v.push_back(cur->val);
                cur = cur->right;
            }
        }
        return v;
    }
};
