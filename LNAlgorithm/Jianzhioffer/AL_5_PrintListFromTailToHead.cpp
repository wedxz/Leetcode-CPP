//
//  AL_PrintListFromTailToHead.cpp
//  LNDemo
//
//  Created by vvusu on 6/19/19.
//  Copyright © 2019 vvusu. All rights reserved.
//

#include "Algorithm.hpp"

/*
 005-从尾到头打印链表
 
 描述:
    输入一个链表，从尾到头打印链表每个节点的值。
 
 示例:
    反转链表
 
 解题思路:
    利用栈的后进先出特性
        单链表的遍历只能从前往后，但是需要从尾往头输出，这不是典型的"先进后出"么，那么我们可以用栈模拟输出
        每经过一个结点的时候，把该结点放到一个栈中。当遍历完整个链表后，再从栈顶开始逐个输出结点的值，此时输出的结点的顺序已经反转过来了。
 
    递归实现
        递归在本质上就是一个栈结构，于是很自然地想到用递归来实现。要实现反过来输出链表，每访问到一个结点的时候，先递归输出它后面的结点，再输出该结点自身，这样链表的输出结构就反过来了。
        只要当前节点不为NULL，也就是链表没到头，就一直递归
        在递归结束时，将元素压入
        这样当递归结束进行返回时，会将递归栈中的数据依次压入vector中，而压入的顺序就是栈中的顺序，即从尾到头
 */

// 利用栈的后进先出特性
static vector<int> printListFromTailToHead_stack(struct ListNode* head)
{
    ListNode *node = head;
    stack<int> st;
    int count = 0;
    while(node != NULL)
    {
        st.push(node->val);
        count++;
        node = node->next;
    }
    
    // 为了效率我们静态vector开辟空间
    vector<int> res(count);
    for(int i = 0; i < count && st.empty() != true; i++)
    {
        // 如果静态开辟vector不能使用push_back
        // 否则会在原来数据的基础上增加
        res.push_back(st.top());
//        res[i] = st.top();
        st.pop();
    }
    return res;
}

// 递归实现
static void printListFromTailToHead_recursive(struct ListNode* head, vector<int> &res)
{
    if(head != NULL)
    {
        printListFromTailToHead_recursive(head->next, res);
        // 尾部添加数据
        res.push_back(head->val);
    }
}

static vector<int> printListFromTailToHead(struct ListNode* head)
{
    vector<int> res;
    printListFromTailToHead_recursive(head, res);
    return res;
}


static ListNode* printListFromTailToHead2(ListNode* head)
{
    if (head == NULL|| head->next == NULL) return head;
    ListNode *newHead = printListFromTailToHead2(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;
}

// Test
static void printListFromTailToHead_test()
{
    ListNode list[4] = {{0},{0},{0},{0}};
    list[0].val = 1;
    list[0].next = &list[1];
    list[1].val = 2;
    list[1].next = &list[2];
    list[2].val = 3;
    list[2].next = &list[3];
    list[3].val = 4;
    list[3].next = NULL;
    
    ListNode *node = &list[0];
    cout <<"Node的元素：";
    ListNode::PrintListNode(node);
    cout <<"\n";
    
    printListFromTailToHead_stack(list);
    vector<int> res = printListFromTailToHead(list);
    for(int i = 0; i < res.size( ); i++)
    {
        cout <<"容器的元素：" <<res[i] <<endl;
    }
}
