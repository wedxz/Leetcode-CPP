//
//  AL_102_BTLevelOrderTraversal.cpp
//  LNAlgorithm
//
//  Created by vvusu on 7/18/19.
//  Copyright © 2019 vvusu. All rights reserved.
//

#include "Algorithm.hpp"

// _102_二叉树的层次遍历
// https://leetcode.com/problems/binary-tree-level-order-traversal/


class AL_102_BTLevelOrderTraversal {
public:
    // 1
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> V;
        if (root == NULL) {
            return V;
        }
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            vector<int> tmp;
            int len = (int)q.size();
            for (int i = 0; i < len; i++) {
                TreeNode *node = q.front();
                q.pop();
                if (node) {
                    tmp.push_back(node->val);
                    if (node->left) {
                        q.push(node->left);
                    }
                    if (node->right) {
                        q.push(node->right);
                    }
                }
            }
            V.push_back(tmp);
        }
        return V;
    }
};
