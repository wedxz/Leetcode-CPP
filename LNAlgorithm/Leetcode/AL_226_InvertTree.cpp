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
 https://leetcode.com/problems/invert-binary-tree/submissions/
 */


class AL_226_InvertTree {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL) {
            return NULL;
        }
        TreeNode *tempNode = root->left;
        root->left = root->right;
        root->right = tempNode;
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
    
    TreeNode* invertTree2(TreeNode* root) {
        if (root == NULL) {
            return NULL;
        }
        TreeNode *tempNode = root->left;
        invertTree2(root->left);
        root->left = root->right;
        root->right = tempNode;
        invertTree2(root->left);
        return root;
    }
    
    
    TreeNode* invertTree3(TreeNode* root) {
        if (root == NULL) {
            return NULL;
        }
        TreeNode *tempNode = root->left;
        invertTree3(root->left);
        invertTree3(root->right);
        root->left = root->right;
        root->right = tempNode;
        return root;
    }
    
    
    TreeNode* invertTree4(TreeNode* root) {
        if (root == NULL) {
            return NULL;
        }
        queue<TreeNode *> q;
        q.push(root);
        
        while (!q.empty()) {
            TreeNode *node = q.front();
            q.pop();
            TreeNode *tmp = node->left;
            node->left = node->right;
            node->right = tmp;
            if (node->left != NULL) {
                q.push(node->left);
            }
            if (node->right != NULL) {
                q.push(node->right);
            }
        }
        return root;
    }
};
