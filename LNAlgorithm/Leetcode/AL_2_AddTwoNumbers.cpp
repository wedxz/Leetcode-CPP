//
//  AL_AddTwoNumbers.cpp
//  
//
//  Created by vvusu on 6/18/19.
//

#include "Algorithm.hpp"

/*
 两数相加
 https://leetcode.com/problems/add-two-numbers/
 描述:
    给定两个非空链表来代表两个非负整数，位数按照逆序方式存储，它们的每个节点只存储单个数字。将这两数相加会返回一个新的链表。
    你可以假设除了数字 0 之外，这两个数字都不会以零开头。
 
 示例：
    输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
    输出：7 -> 0 -> 8
    原因：342 + 465 = 807
 
 解题思路：
    这道题最忌讳的是分别把两个链表中的数字转换为各自表示的整数，然后把转换后的两个整数相加，最后再把相加的结果转换成链表输出，虽然这种思路非常简单、
    原始，但感觉有点愚笨。我们可以避免链表与整数间转换的资源浪费，这得益于链表的表头为整数的最低位，直接从两个链表的表头开始相加对应的数字，
    然后用这个数字创建新的链表节点，直到其中一个链表的表尾为止，因为两个链表的长度不一定相同，期间发生了进位需要处理进位的数字，还需要注意较长的列表以及最高一位的进位。
 */

static ListNode* addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
    ListNode *ret = new ListNode(0);
    ListNode *cur = ret;
    ListNode *p = l1, *q = l2;
    int carry = 0;
    while (p || q)
    {
        int x = p ? p->val : 0;
        int y = q ? q->val : 0;
        int sum = carry + x + y;
        carry = sum / 10;
        cur->next = new ListNode(sum % 10);
        cur = cur->next;
        if (p) p = p->next;
        if (q) q = q->next;
    }
    if (carry)
    {
        cur->next = new ListNode(1);
    }
    return ret->next;
}

// 测试
static void addTwoNumbers_test()
{
    ListNode *a1 = new ListNode(2);
    ListNode *a2 = new ListNode(4);
    ListNode *a3 = new ListNode(3);
    ListNode *b1 = new ListNode(5);
    ListNode *b2 = new ListNode(6);
    ListNode *b3 = new ListNode(9);
    a1->next = a2;
    a2->next = a3;
    a3->next = NULL;
    b1->next = b2;
    b2->next = b3;
    b3->next = NULL;

    ListNode *list = addTwoNumbers(a1, b1);
    cout <<"两个链表相加:\n"
         <<"A " <<a1->val <<"->" <<a2->val <<"->" <<a3->val <<"\n"
         <<"B " <<b1->val <<"->" <<b2->val <<"->" <<b3->val <<endl;

    while (list != NULL)
    {
        cout << list->val <<endl;
        list = list->next;
    };
}
