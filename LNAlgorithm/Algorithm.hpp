//
//  Algorithm.hpp
//  LNDemo
//
//  Created by vvusu on 6/19/19.
//  Copyright © 2019 vvusu. All rights reserved.
//

#ifndef Algorithm_hpp
#define Algorithm_hpp

#include <iostream>
#include <queue>
#include <stack>
#include <stdio.h>
#include <unordered_map>
#include <vector>

using namespace std;

// 调试开关
#define __tmain main
#ifdef __tmain
#define debug cout
#else
#define debug 0 && cout
#endif

// 单向链表
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL)
    {
    }
    
    // 前序遍历
    static void PrintListNode(ListNode *node)
    {
        if (node == NULL) return;
        cout << " " << node->val;
        PrintListNode(node->next);
    }
    
    static int ListNodeCount(ListNode *node)
    {
        int count = 0;
        ListNode *head = node;
        while (head != NULL) {
            count++;
            head = head->next;
        }
        return count;
    }
};

// 二叉树
/*
 前序遍历：根结点 ---> 左子树 ---> 右子树   考察到一个节点后，即刻输出该节点的值，并继续遍历其左右子树。(根左右)
 中序遍历：左子树 ---> 根结点 ---> 右子树   考察到一个节点后，将其暂存，遍历完左子树后，再输出该节点的值，然后遍历右子树。(左根右)
 后序遍历：左子树 ---> 右子树 ---> 根结点   考察到一个节点后，将其暂存，遍历完左右子树后，再输出该节点的值。(左右根)
 层次遍历：只需按层次遍历即可
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    // 构造函数
    TreeNode(int x) : val(x), left(NULL), right(NULL)
    {
    }
    
    // 前序遍历 - 递归实现
    static void PreOrder(TreeNode *root)
    {
        if (root == NULL) return;
        cout << " " << root->val;
        PreOrder(root->left);
        PreOrder(root->right);
    }
    
    // 中序遍历
    static void InOrder(TreeNode *root)
    {
        if (root == NULL) return;
        InOrder(root->left);
        cout << " " << root->val;
        InOrder(root->right);
    }
    
    // 后序遍历
    static void PostOrder(TreeNode *root)
    {
        if (root == NULL) return;
        PostOrder(root->left);
        PostOrder(root->right);
        cout << " " << root->val;
    }
    
    // 前序遍历 - 栈实现
    static void PreOrderByStack(TreeNode *root)
    {
        if (root == NULL) return;
        stack<TreeNode *> st;
        TreeNode *p = root;
        while (p != NULL || !st.empty()) {
            if (p != NULL) {
                cout << " " << p->val;
                st.push(p);
                p = p->left;
            } else {
                p = st.top();
                st.pop();
                p = p->right;
            }
        }
    }
    
    // 中序遍历 - 栈实现
    static void InOrderByStack(TreeNode *root)
    {
        if (root == NULL) return;
        stack<TreeNode *> st;
        TreeNode *p = root;
        while (p != NULL || !st.empty()) {
            if (p != NULL) {
                st.push(p);
                p = p->left;
            } else {
                p = st.top();
                cout << " " << p->val;
                st.pop();
                p = p->right;
            }
        }
    }
    
    // 后序遍历 - 栈实现
    static void PostOrderByStack(TreeNode *root)
    {
        if (root == NULL) return;
        stack<TreeNode *> st;
        TreeNode *p = root, *q = NULL;
        while (p != NULL || !st.empty()) {
            if (p != NULL) {
                st.push(p);
                p = p->left;
            } else {
                p = st.top();
                if (p->right != NULL && p->right != q) {
                    p = p->right;
                } else {
                    cout << " " << p->val;
                    st.pop();
                    q = p;
                    p = NULL;
                }
            }
        }
    }
    
    // 层次遍历
    // 层次遍历的代码比较简单，只需要一个队列即可，先在队列中加入根结点。之后对于任意一个结点来说，在其出队列的时候，访问之。同时如果左孩子和右孩子有不为空的，入队列
    // 后序遍历 - 栈实现
    static void levelOrder(TreeNode *root)
    {
        if (root == NULL) return;
        // 队列
        queue<TreeNode *> q;
        q.push(root);
        TreeNode *p;
        while (!q.empty()) {
            // 访问队首元素  q.back() 访问队尾元素q
            p = q.front();
            q.pop();
            cout << " " << p->val;
            if (p->left != NULL)
                q.push(p->left);
            if (p->right != NULL)
                q.push(p->right);
        }
    }
    
    // 深度优先遍历
    // 其实深度遍历就是上面的前序、中序和后序。但是为了保证与广度优先遍历相照应，也写在这。代码也比较好理解，其实就是前序遍历
    static void DepthOrder(TreeNode *root)
    {
        if (root == NULL) return;
        TreeNode *p;
        stack<TreeNode *> st;
        st.push(root);
        while (!st.empty()) {
            p = st.top();
            cout << " " << p->val;
            st.pop();
            if (p->right != NULL) {
                st.push(p->right);
            }
            if (p->left != NULL) {
                st.push(p->left);
            }
        }
    }
};

#endif /* Algorithm_hpp */
