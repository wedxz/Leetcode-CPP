//
//  AL_145_BTPostorderTraversal.cpp
//  LNAlgorithm
//
//  Created by vvusu on 7/17/19.
//  Copyright © 2019 vvusu. All rights reserved.
//

#include "Algorithm.hpp"



// _145_二叉树的后序遍历
// https://leetcode.com/problems/binary-tree-postorder-traversal/


class AL_145_BTPostorderTraversal {
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
        preorderTreeNode(root->right, v);
        v.push_back(root->val);
    }
    
    // 2
    vector<int> preorderTraversal2(TreeNode* root) {
        vector<int> v;
        stack<TreeNode *> s;
        TreeNode *cur = root, *q = NULL;
        while (cur || !s.empty()) {
            if (cur) {
                s.push(cur);
                cur = cur->left;
            } else {
                cur = s.top();
                if (cur->right != NULL && cur->right != q) {
                    cur = cur->right;
                } else {
                    v.push_back(cur->val);
                    s.pop();
                    q = cur;
                    cur = NULL;
                }
                cur = cur->right;
            }
        }
        return v;
    }
};
