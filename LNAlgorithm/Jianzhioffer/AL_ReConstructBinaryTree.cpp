//
//  AL_ReConstructBinaryTree.cpp
//  LNDemo
//
//  Created by vvusu on 6/19/19.
//  Copyright © 2019 vvusu. All rights reserved.
//

#include "Algorithm.hpp"

/*
 006-重建二叉树
 
 描述:
    输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。
    假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
 
 示例:
    前序遍历序列{1,2,4,7,3,5,6,8}
    中序遍历序列{4,7,2,1,5,3,8,6}
 
 解题思路:
    这道题还是比较简单的，我们知道
    前序遍历的顺序为：根左右
    中序遍历的顺序为：左根右
 
    递归思想
    1.我们先根据前序遍历序列的第一个确定根，然后在中序遍历的序列中找到根的位置，根左边的就是其左子树，右边就是其右子树
    2.构建根和左右子树
    3.递归的进行1和2
 */

static struct TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> in)
{
    //  前序遍历的长度跟中序遍历的长度应该相同
    if(pre.size() != in.size())  return NULL;
    // 长度不能为0
    if(pre.size() == 0) return NULL;
    
    // 前序遍历的第一个结点是根节点
    int value = pre[0];
    int length = (int)pre.size();
    TreeNode *root = new TreeNode(value);
    
    // 在中序遍历中查找到根的位置
    int rootIndex = 0;
    for(rootIndex = 0; rootIndex < length; rootIndex++)
    {
        if (in[rootIndex] == value) break;
    }
    if(rootIndex >= length) return NULL;
    
    ///  区分左子树和右子树
    ///  中序遍历中, 根左边的就是左子数, 右边的就是右子树
    ///  前序遍历中, 根后面是先遍历左子树, 然后是右子树
    
    ///  首先确定左右子树的长度, 从中序遍历in中确定
    int leftLength = rootIndex;
    int rightLength = length - 1 - rootIndex;
    vector<int> preLeft(leftLength), inLeft(leftLength);
    vector<int> preRight(rightLength), inRight(rightLength);
    for(int i = 0; i < length; i++)
    {
        if(i < rootIndex)
        {
            //  前序遍历的第一个是根节点, 根后面的(leftLegnth = rootIndex) - 1个节点是左子树, 因此是i+1
            preLeft[i] = pre[i + 1];
            //  中序遍历前(leftLength = rootIndex) - 1个节点是左子树, 第rootIndex个节点是根
            inLeft[i] = in[i];
        }
        else if(i > rootIndex)
        {
            //  前序遍历的第一个是根节点, 根后面的(leftLegnth = rootIndex) - 1个节点是左子树, 后面是右子树
            preRight[i - rootIndex - 1] = pre[i];
            //  中序遍历前(leftLength = rootIndex) - 1个节点是左子树, 第rootIndex个节点是根, 然后是右子树
            inRight[i - rootIndex - 1] = in[i];
        }
    }
    
    root->left = reConstructBinaryTree(preLeft, inLeft);
    root->right = reConstructBinaryTree(preRight, inRight);
    return root;
}

// Test
static void reConstructBinaryTree_test()
{
    int pre[] = { 1, 2, 4, 7, 3, 5, 6, 8 };
    int in[] = { 4, 7, 2, 1, 5, 3, 8, 6 };
    vector<int> preOrder(pre, pre + 8);
    vector<int> inOrder(in, in + 8);
    
    TreeNode *root = reConstructBinaryTree(preOrder, inOrder);
    cout <<"重建二叉树" <<endl;
    cout <<"  前序遍历:";
    TreeNode::PreOrder(root);
    cout <<endl;
    
    cout <<"  前序遍历:";
    TreeNode::PreOrderByStack(root);
    cout <<endl;
    
    cout <<"  中序遍历:";
    TreeNode::InOrder(root);
    cout <<endl;
    
    cout <<"  中序遍历:";
    TreeNode::InOrderByStack(root);
    cout <<endl;
    
    cout <<"  后序遍历:";
    TreeNode::PostOrder(root);
    cout <<endl;
    
    cout <<"  后序遍历:";
    TreeNode::PostOrderByStack(root);
    cout <<endl;
    
    cout <<"  层次遍历:";
    TreeNode::levelOrder(root);
    cout <<endl;
    
    cout <<"  深度遍历:";
    TreeNode::DepthOrder(root);
    cout <<endl;
}
